package main

import (
	"fmt"
	"os"
)

func main() {
	data, err := os.ReadFile("sometext.txt")
	if err != nil {
		panic(err)
	}
	fmt.Println("sometext.txt has:")
	fmt.Println(string(data))
}
