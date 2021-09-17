package goroutines

import (
	"bufio"
	"fmt"
	"os"
	"os/signal"
	"strconv"
	"sync"
	"syscall"
	"time"
)

var wg sync.WaitGroup = sync.WaitGroup{}

func Run(poolSize int) {

	maxJobs := 1000
	jobs := make(chan float64, maxJobs)
	done := make(chan struct{}, 1)
	go trapSigTerm(done)
	input := make(chan string, 1)
	curWorker := 1
	// go waitSeconds(10, done)
	go readInput(input)
fromloop:
	for {
		select {
		case <-done:
			break fromloop
		case task := <-input:
			if len(task) == 0 {
				break
			}
			job, err := strconv.ParseFloat(task[:len(task)-1], 64)
			if err != nil {
				break
			}
			if curWorker <= poolSize {
				fmt.Printf("worker:%d spawning\n", curWorker)
				wg.Add(1)
				go worker(curWorker, jobs)
				curWorker++
			}
			jobs <- job
		}
	}
	close(jobs)
	wg.Wait()
}

func readInput(inp chan string) {
	for {
		taskReader := bufio.NewReader(os.Stdin)
		task, _ := taskReader.ReadString('\n')
		inp <- task
	}
}

func waitSeconds(sec int, done chan struct{}) {
	time.Sleep(time.Duration(sec) * time.Second)
	done <- struct{}{}
}

func worker(id int, jobs <-chan float64) {
	for j := range jobs {
		fmt.Printf("worker:%d sleep:%.1f\n", id, j)
		time.Sleep(time.Duration(j) * time.Second)
		// fmt.Printf("worker:%d slept %f\n", id, j)
	}
	fmt.Printf("worker:%d stopping\n", id)
	wg.Done()
}

func trapSigTerm(done chan struct{}) {
	c := make(chan os.Signal, 1)
	signal.Notify(c, os.Interrupt, syscall.SIGTERM)
	<-c
	done <- struct{}{}
}
