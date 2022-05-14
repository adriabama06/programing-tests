package main

import "fmt"

type PersonIsMenorType func(Person) bool

func PersonIsMenor(person Person) bool {
	if person.age < 18 {
		person.menor = true
	} else {
		person.menor = false
	}
	return person.menor
}

type Person struct {
	name    string
	age     int
	menor   bool
	isMenor PersonIsMenorType
}

func main() {
	var person Person = Person{name: "John", age: 30, menor: false, isMenor: PersonIsMenor}
	person.isMenor(person)

	fmt.Println(person)
	fmt.Printf("Hello %s, you have %d years old, can you drink? %t", person.name, person.age, person.menor)
}
