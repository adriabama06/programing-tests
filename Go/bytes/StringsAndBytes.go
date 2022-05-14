package main

import "fmt"

func main() {
	var name string = "Gopher"
	var nameInBytes []byte = []byte(name)

	fmt.Println(name)
	fmt.Println(string(nameInBytes))
}
