package main

import (
	"fmt"
	"time"
)

func print(message string, who string) {
	for i := 0; i < 5; i++ { // print 5 times the message
		time.Sleep(100 * time.Millisecond) // sleep 100ms
		fmt.Printf("%s: %s\n", who, message)
	}
}

func main() {
	go print("Hello World", "At Go")   // this will run in a separate thread, and will print "Hello World" 5 times
	time.Sleep(600 * time.Millisecond) // sleep 600ms
	// why wait, this is not runing at main thread, because this dont affect at main thread
	//print("Hello World", "Main")
}
