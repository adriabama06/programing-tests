package main

import "fmt"

func main() {
	var age int = 23
	var ageInBytes byte = byte(age)

	fmt.Println(age)
	fmt.Println(int(ageInBytes))
}
