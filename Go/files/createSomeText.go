package main

import (
	"fmt"
	"os"
)

func main() {
	os.WriteFile("sometext.txt", []byte("Some Text"), 0644)
	fmt.Println("sometext.txt has writted!")
}
