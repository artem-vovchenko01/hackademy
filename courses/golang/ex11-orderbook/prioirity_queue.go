package orderbook

import (
	"strconv"
	"time"
)

type QueueItem struct {
	value     Order
	priority  uint64
	timestamp time.Time
	index     int
}

func (qi *QueueItem) String() string {
	return "Side: " + qi.value.Side.String() + ", kind: " + qi.value.Kind.String() + ", Volume: " + strconv.FormatUint(qi.value.Volume, 10) + ", Price: " + strconv.FormatUint(qi.value.Price, 10)
}

type PriorityQueue []*QueueItem

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	if pq[i].priority == pq[j].priority {
		return pq[i].timestamp.Before(pq[j].timestamp)
	}
	return pq[i].priority > pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = int(i)
	pq[j].index = int(j)
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*QueueItem)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil
	item.index = -1
	*pq = old[0 : n-1]
	return item
}

func (pq *PriorityQueue) CanFillAmount(requestedAmount uint64) bool {
	old := *pq
	n := len(old)
	if n == 0 {
		return false
	}
	amount := uint64(0)
	for amount < requestedAmount {
		if n == 0 {
			return false
		}
		n--
		amount += old[n].value.Volume
	}
	return true
}

func (pq *PriorityQueue) Peek() (interface{}, bool) {
	old := *pq
	n := len(old)
	if n == 0 {
		return nil, false
	}
	item := old[n-1]
	return item, true
}
