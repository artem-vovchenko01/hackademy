package main

import (
	"fmt"
	"math/rand"
	"time"
)

type Shop struct {
	queue SeatQueue
}

type Barber struct{}

var shop = Shop{queue: CreateSeats(15)}

func main() {
	quit := make(chan struct{})
	customerChannel := make(chan int, 1)
	customerReady := make(chan struct{}, 1)
	queueSync := make(chan struct{}, 1)
	customerServed := make(chan struct{}, 1)

	queueSync <- struct{}{}
	var numberOfCustomers = 20
	go customer(customerChannel, customerReady, quit, queueSync)
	go barber(customerReady, quit, queueSync, customerServed)
	go ensureAllServed(customerServed, quit, numberOfCustomers)

	for customer := 1; customer <= numberOfCustomers; customer++ {
		randomDelay()
		customerChannel <- customer
	}

	<-quit
}

func ensureAllServed(customerServed, quit chan struct{}, customers int) {
	counter := 0
	for {
		<-customerServed
		counter++
		if counter == customers {
			break
		}
	}
	quit <- struct{}{}
	quit <- struct{}{}
}

func customer(customerChan chan int, cReady, quit, queueSync chan struct{}) {
	for {
		select {
		case customer := <-customerChan:
			fmt.Printf("Customer %d came, tries to find place in the queue\n", customer)
			<-queueSync
			err := shop.queue.AddCustomer(customer)
			queueSync <- struct{}{}
			if err != nil {
				fmt.Printf("Queue is full, customer %d cannot come\n", customer)
			} else {
				fmt.Printf("Customer %d took a seet\n", customer)
				cReady <- struct{}{}
			}
		case <-quit:
			break
		}
	}
}

func barber(cReady, quit, queueSync, customerServed chan struct{}) {
	for {
		select {
		case <-cReady:
			<-queueSync
			var customer, err = shop.queue.NextCustomer()
			if err == nil {
				fmt.Printf("Barber is serving customer %d\n", customer)
				fmt.Printf("People in queue: %v\n", shop.queue.seats)
				queueSync <- struct{}{}
				randomDelay()
				fmt.Printf("Done serving customer %d\n", customer)
				customerServed <- struct{}{}
			} else {
				queueSync <- struct{}{}
				fmt.Println("There is no customer to ask from the queue!")
			}

		case <-quit:
			quit <- struct{}{}
			break
		}
	}
}

func randomDelay() {
	time.Sleep(time.Duration(rand.Intn(100)) * time.Millisecond)
}
