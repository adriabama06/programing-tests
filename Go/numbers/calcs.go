package main

import "fmt"

func add(x int, y int) int {
	return x + y
}

func remove(x int, y int) int {
	return x - y
}

func muiltiply(x int, y int) int {
	return x * y
}

func divide(x int, y int) int {
	return x / y
}

func update(variable *int, newvalue int) {
	*variable = newvalue
	return
}

func main() {
	var number int = 5
	var number2 int = 5
	fmt.Println("Test number: ", number)
	fmt.Println("Add 5: ", add(number, number2))
	fmt.Println("Remove 5: ", remove(number, number2))
	fmt.Println("Multiply 5: ", muiltiply(number, number2))
	fmt.Println("Divide 5: ", divide(number, number2))

	fmt.Print("---\n\n---")

	// is only for test the variable and pointers :C C/C++ pointers AAAAAAAAAAhhhhhhhhh
	update(&number, 2)

	fmt.Println("Test number: ", number)
	fmt.Println("Add 5: ", add(number, number2))
	fmt.Println("Remove 5: ", remove(number, number2))
	fmt.Println("Multiply 5: ", muiltiply(number, number2))
	fmt.Println("Divide 5: ", divide(number, number2))
}
