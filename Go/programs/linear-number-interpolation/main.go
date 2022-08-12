package main

import "fmt"

func printArray(arr []float32) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("[%d] = %f\n", i, arr[i])
	}
	fmt.Print("\n")
}

func work(i int, smallnumber *float32, diferenceByPrecission *float32, arr *[]float32) {
	(*arr)[i] = *smallnumber + (*diferenceByPrecission * float32(i+1))
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

	for i := 0; i < precission; i++ {
		work(i, &smallnumber, &diferenceByPrecission, &toreturn)
	}

	return toreturn
}

func main() {
	result := interpolate(0, 100, 4)

	printArray(result)
}
