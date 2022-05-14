package main

import "fmt"

func main() {
	var number1 int = 0
	var number2 int = 0
	fmt.Print("\nWrite the number 1: ")
	fmt.Scanf("%d", &number1)
	fmt.Print("Write the number 2 to add: ")
	fmt.Scanf("%d", &number2)

	fmt.Printf("\n%d + %d = %d\n\n", number1, number2, number1+number2)
}
