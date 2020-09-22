package main

import "math"

func generate(digit int, start int) int {
	rs := 0
	for loop := start; loop < digit+start; loop++ {
		rs *= 10
		rs += loop
	}

	return rs
}

func sequentialDigits(low int, high int) []int {
	result := []int{}
	dl := math.Floor(math.Log10(float64(low)) + 1)
	dh := math.Floor(math.Log10(float64(high)) + 1)

	for loop := dl; loop <= dh; loop++ {
		start := 1
		for start <= 10-int(loop) {
			number := generate(int(loop), start)
			if number >= low && number <= high {
				result = append(result, number)
			}
			start += 1
		}
	}

	return result
}
