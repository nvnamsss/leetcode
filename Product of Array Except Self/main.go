package main

func productExceptSelf(nums []int) []int {
	length := len(nums)
	output := make([]int, length)

	if length == 0 {
		return output
	}

	t := nums[0]
	output[0] = 1
	for loop := 1; loop < length; loop++ {
		output[loop] = t
		t *= nums[loop]
	}

	t = nums[length-1]
	for loop := length - 2; loop >= 0; loop-- {
		output[loop] *= t
		t *= nums[loop]
	}

	return output
}
