package main

import (
	"fmt"
	"math"
)

func calculate(s string) int32 {
	n := len(s)
	var ans int32
	i := 0

	for i < n {
		j := i
		for j < n && s[i] == s[j] {
			j++
		}

		ans += int32(math.Floor(float64(j-i) / 2))
		i = j
	}

	return ans
}

func solution(arr []string) []int32 {
	res := make([]int32, len(arr))
	for i, s := range arr {
		res[i] = calculate(s)
	}
	return res
}

func main() {
	testCases := []string{
		"aaaaaaa",
		"AABAAB",
		"ABAB",
		"AAAA",
		"BBAABB",
	}

	results := solution(testCases)

	fmt.Println("Results for each test case:")
	for i, result := range results {
		fmt.Printf("Test case \"%s\": %d\n", testCases[i], result)
	}
}
