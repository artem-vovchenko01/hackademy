package main

import (
	"errors"
)

type SeatQueue struct {
	seats []int
	cap 	int
}

func CreateSeats(capacity int) SeatQueue {
	return SeatQueue {
		seats: make([]int, 0),
		cap: capacity,
	}
}

func (seatOrder *SeatQueue) AddCustomer(customer int) error {
	if (len(seatOrder.seats) < seatOrder.cap) {
		seatOrder.seats = append([]int{customer}, seatOrder.seats...)
		return nil
	} else {
		return errors.New("There are no free seats in the queue")
	}
}

func (seatOrder *SeatQueue) IsFreeSeatAvailable() bool {
	return len(seatOrder.seats) < seatOrder.cap
}

func (seatOrder *SeatQueue) NextCustomer() (int, error) {
	var val int
	val, seatOrder.seats = seatOrder.seats[0], seatOrder.seats[1:]
	if val == 0 {
		return val, errors.New("There are no customers in the queue")
	} else {
		return val, nil
	}
}
