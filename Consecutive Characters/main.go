package main

type Type interface {
	GetType() string
}

type Animal interface {
	Eat()
	Run()
}

type Leg struct {
}

type Cat struct {
	Leg
	private int64
	Public  int64
}

func swap(a, b int) (int, int) {
	// 3 4
	return b, a
	// a = a + b // 7
	// b = a - b // 3
	// a = a - b // 4
}

func main() {
	arr := []int{1, 2, 3}
	if len(arr) == 0 {
		// empty
	}
	go func() {
		// doing concurently
	}()
}
