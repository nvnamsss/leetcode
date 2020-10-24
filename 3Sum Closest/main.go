package main

import (
	"math"
	"sort"
)

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func threeSumClosest(nums []int, target int) int {
	sort.Slice(nums, func(i, j int) bool { return nums[i] < nums[j] })

	dif := math.MaxInt16
	n := len(nums)
	for loop := 0; loop < n; loop++ {
		lo := loop + 1
		hi := n - 1
		for lo < hi {
			sum := nums[loop] + nums[lo] + nums[hi]
			if abs(target-sum) < abs(dif) {
				dif = target - sum
			}

			if sum < target {
				lo++
			} else {
				hi--
			}
		}
	}
	return target - dif
}

func main() {

}
