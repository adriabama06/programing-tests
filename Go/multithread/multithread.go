package main

import (
	"fmt"
	"sync"
)

func main() {
	myStringArray := []string{"h", "e", "l", "l", "o", " ", "w", "o", "r", "l", "d"}
	myStringArrayLen := len(myStringArray)

	var wg sync.WaitGroup
	// Tell the 'wg' WaitGroup how many threads/goroutines
	// that are about to run concurrently.
	wg.Add(myStringArrayLen)

	fmt.Println("Starting Loop...")

	for i := 0; i < myStringArrayLen; i++ {
		// Spawn a thread for each iteration in the loop.
		// Pass 'i' into the goroutine's function
		//   in order to make sure each goroutine
		//   uses a different value for 'i'.
		go func(i int) {
			// At the end of the goroutine, tell the WaitGroup
			//   that another thread has completed.
			defer wg.Done()
			fmt.Printf("Index %d: %v\n", i, myStringArray[i])
		}(i)
	}

	fmt.Println("Do something extra at main process while goroutines are running...")

	// Wait for `wg.Done()` to be exectued the number of times
	//   specified in the `wg.Add()` call.
	// `wg.Done()` should be called the exact number of times
	//   that was specified in `wg.Add()`.
	// If the numbers do not match, `wg.Wait()` will either
	//   hang infinitely or throw a panic error.
	wg.Wait()

	fmt.Println("Loop Finished")
}
