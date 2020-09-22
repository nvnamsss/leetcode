package main

func search(nums []int, target int) int {
	l := 0
	r := len(nums)
	for l <= r {
		mid := l + (r-l)/2
		if target == nums[mid] {
			return mid
		}

		if nums[l] <= nums[mid] {
			if target < nums[mid] && target >= nums[l] {
				r = mid - 1
			} else {
				l = mid + 1
			}
		} else {
			if target > nums[mid] && target <= nums[r] {
				l = mid + 1
			} else {
				r = mid - 1
			}
		}
	}

	return -1
}
