package orderbook

import (
	"container/heap"
	"time"
)

type Orderbook struct {
	bids      *PriorityQueue
	asks      *PriorityQueue
	completed []*Order
}

func New() *Orderbook {
	var bid PriorityQueue = make(PriorityQueue, 0)
	var ask PriorityQueue = make(PriorityQueue, 0)
	return &Orderbook{
		bids: &bid,
		asks: &ask,
	}
}

func (orderbook *Orderbook) Match(order *Order) ([]*Trade, *Order) {
	if order.Side == SideAsk {
		return orderbook.MatchAsk(order)
	} else {
		return orderbook.MatchBid(order)
	}
}

func (orderbook *Orderbook) MatchAsk(order *Order) ([]*Trade, *Order) {
	trades := make([]*Trade, 0)
	for {
		if orderbook.bids.Len() == 0 {
			if order.Kind == KindLimit {
				item := &QueueItem{value: *order, timestamp: time.Now(), priority: (^uint64(0)) - order.Price}
				heap.Push(orderbook.asks, item)
			} else {
				return trades, order
			}
			break
		}

		highestBidQueueItem := heap.Pop(orderbook.bids)
		highestBid := highestBidQueueItem.(*QueueItem).value
		heap.Push(orderbook.bids, highestBidQueueItem)
		if order.Kind == KindMarket || order.Price <= highestBid.Price {
			trade := executeTrade(order, &highestBid)
			trades = append(trades, trade)
			if highestBid.Volume == 0 {
				heap.Pop(orderbook.bids)
			}
			if order.Volume == 0 {
				break
			}
		} else {
			item := &QueueItem{value: *order, timestamp: time.Now(), priority: (^uint64(0)) - order.Price}
			heap.Push(orderbook.asks, item)
			break
		}
	}

	return trades, nil
}

func (orderbook *Orderbook) MatchBid(order *Order) ([]*Trade, *Order) {
	trades := make([]*Trade, 0)
	for {
		if orderbook.asks.Len() == 0 {
			if order.Kind == KindLimit {
				item := &QueueItem{value: *order, timestamp: time.Now(), priority: order.Price}
				heap.Push(orderbook.bids, item)
			} else {
				return trades, order
			}
			break
		}

		lowestAskQueueItem := heap.Pop(orderbook.asks)
		lowestAsk := lowestAskQueueItem.(*QueueItem).value
		heap.Push(orderbook.asks, lowestAskQueueItem)
		if order.Kind == KindMarket || order.Price >= lowestAsk.Price {
			trade := executeTrade(order, &lowestAsk)
			trades = append(trades, trade)
			if lowestAsk.Volume == 0 {
				heap.Pop(orderbook.asks)
			}
			if order.Volume == 0 {
				break
			}
		} else {
			item := &QueueItem{value: *order, timestamp: time.Now(), priority: order.Price}
			heap.Push(orderbook.bids, item)
			break
		}
	}

	return trades, nil
}

func executeTrade(incoming *Order, resting *Order) *Trade {
	var amount uint64
	if resting.Volume >= incoming.Volume {
		amount = incoming.Volume
	} else {
		amount = resting.Volume
	}

	incoming.Volume -= amount
	resting.Volume -= amount
	if incoming.Side == SideAsk {
		return &Trade{Volume: amount, Price: resting.Price, Ask: incoming, Bid: resting}
	} else {
		return &Trade{Volume: amount, Price: resting.Price, Ask: resting, Bid: incoming}
	}
}

func (pq *PriorityQueue) update(item *QueueItem, value Order) {
	item.value = value
	item.priority = item.value.Price
	heap.Fix(pq, item.index)
}
