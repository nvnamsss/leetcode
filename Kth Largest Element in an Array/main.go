package main

import "log"

func partition(nums []int, left, right, pivot int) int {
	var (
		storeIndex = left
		pivotValue = nums[pivot]
	)

	nums[right], nums[pivot] = nums[pivot], nums[right]
	for i := left; i <= right; i++ {
		if nums[i] > pivotValue {
			nums[i], nums[storeIndex] = nums[storeIndex], nums[i]
			storeIndex++
		}
	}
	nums[right], nums[storeIndex] = nums[storeIndex], nums[right]

	return storeIndex
}

func quickselect(nums []int, left, right, k int) {
	if left >= right {
		return
	}
	p := left
	p = partition(nums, left, right, p)
	if p == k {
		return
	}

	if p < k {
		quickselect(nums, p+1, right, k)
	} else {
		quickselect(nums, left, p-1, k)
	}
}

func findKthLargest(nums []int, k int) int {
	quickselect(nums, 0, len(nums)-1, k-1)
	log.Printf("k: %v", k)
	return nums[k-1]
}

func main() {
	var (
		nums []int = []int{3, 2, 1, 5, 6, 4}
		rs   int
	)
	rs = findKthLargest(nums, 2)
	log.Printf("%v", rs)

	nums = []int{1, 2}
	rs = findKthLargest(nums, 2)
	log.Printf("%v", rs)

	nums = []int{3, 3, 3, 3, 3, 3, 3, 3, 3}
	rs = findKthLargest(nums, 8)
	log.Printf("%v", rs)
}
