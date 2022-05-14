package main

import "fmt"

func helloWorld() { // is not exported helloWorld -> HelloWorld for get exported
	fmt.Println("And\nHello World")
}

func SayHi() {
	fmt.Println("Hi")
}

func SayAll() {
	SayHi()
	helloWorld()
}
