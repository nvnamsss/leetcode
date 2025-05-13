package main

func simulate(nums []int, target int, k int) bool {
	for i := 0; i < len(nums); i++ {
		if nums[i] > target {
			continue
		}

		k--
		i++
		if k == 0 {
			return true
		}
	}

	return false
}

func minCapability(nums []int, k int) int {
	var (
		l = 0
		r = 0
	)

	for i := 0; i < len(nums); i++ {
		if nums[i] > r {
			r = nums[i]
		}
	}

	for l < r {
		mid := l + (r-l)/2
		if simulate(nums, mid, k) {
			r = mid
		} else {
			l = mid + 1
		}
	}

	return l
}
