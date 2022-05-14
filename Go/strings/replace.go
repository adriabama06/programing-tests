package main

import (
	"fmt"
	"strings"
)

func main() {
	var ExampleString string = "example string, eee"
	// sring.Replace(string to replace, char to replace, new char, max number of replacements (-1 = all))
	fmt.Println(strings.Replace(ExampleString, "e", "E", 2))
	fmt.Println(strings.Replace(ExampleString, "e", "E", -1))
	fmt.Println(strings.ReplaceAll(ExampleString, "e", "E"))
}
