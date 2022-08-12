package main

import (
	"fmt"
	"os"
	"runtime"
	"sync"
)

var MAX_THREADS int = runtime.NumCPU()
var wg sync.WaitGroup

func save(arr *[]float32) {
	f, err := os.Create("resultGo.txt")
	if err != nil {
		return
	}

	var cuantity int = 1000000

	var limitedSelection int = len(*arr) / cuantity

	for i := 0; i < cuantity; i++ {
		f.WriteString(fmt.Sprintf("%d %f\n", i*limitedSelection, (*arr)[i*limitedSelection]))
	}
	f.Close()
}

func work(startIndex int, endIndex int, smallnumber *float32, diferenceByPrecission *float32, arr *[]float32, isThread bool) {

	for i := startIndex; i < endIndex; i++ {
		(*arr)[i] = *smallnumber + (*diferenceByPrecission * float32(i+1))
	}

	if isThread {
		defer wg.Done()
	}
}

func interpolate(x float32, y float32, precission int) []float32 {
	var toreturn []float32 = make([]float32, precission)

	var smallnumber float32 = x
	var diference float32 = y - x

	if x > y {
		smallnumber = y
		diference = x - y
	}

	var diferenceByPrecission float32 = diference / float32(precission+1)

	if precission < MAX_THREADS {
		work(0, precission, &smallnumber, &diferenceByPrecission, &toreturn, false)
	} else {
		var numberToAddToIndex int = precission / MAX_THREADS

		wg.Add(MAX_THREADS)

		for i := 0; i < MAX_THREADS; i++ {
			go work(i*numberToAddToIndex, (i+1)*numberToAddToIndex, &smallnumber, &diferenceByPrecission, &toreturn, true)
		}

		wg.Wait()
	}

	return toreturn
}

func main() {
	result := interpolate(0, 1000, 450000000)

	save(&result)
}
