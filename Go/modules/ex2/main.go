package main

import (
	"example/exampleText"
	"fmt"
)

func main() {
	fmt.Println(exampleText.GetHello() + " " + exampleText.GetWorld())
	fmt.Println(exampleText.GetFoo() + " " + exampleText.GetBar())
}
