package solution

import "math"

// you can also use imports, for example:
// import "fmt"
// import "os"

// you can write to stdout for debugging purposes, e.g.
// fmt.Println("this is a debug message")

func Solution(N int) int {
	// write your code in Go 1.4
	rs := 0
	index := int64(math.Ceil(math.Log2(float64(N))))
	count := 0
	for index > 0 {
		t := (N & (1<<index - 1)) != 0
		if t && count > 0 {
			rs = int(math.Max(float64(rs), float64(count)))
			count = 0
		}

		if !t {
			count++
		}
		index--
	}

	return rs
}
