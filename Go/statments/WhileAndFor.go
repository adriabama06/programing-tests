package main

func main() {
	// While Loop not exits
	for i := 10; i > 0; i-- {
		if i == 5 {
			break
		}
		println(i)
	}
	for i := 0; i < 10; i++ {
		println(i)
	}
}
