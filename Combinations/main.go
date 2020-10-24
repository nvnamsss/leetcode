package main

var result [][]int

func combination(n int, list []int, start int, k int) {
	if len(list) == k {
		t := make([]int, len(list))
		copy(t, list)
		result = append(result, t)
		return
	}

	for loop := start; loop <= n; loop++ {
		list = append(list, loop)
		combination(n, list, loop+1, k)
		list = list[:len(list)-1]
	}
}

func combine(n int, k int) [][]int {
	result = [][]int{}
	combination(n, []int{}, 1, k)
	return result
}
