package main

func majorityElement(nums []int) []int {
	result := []int{}

	length := len(nums)
	time := length / 3
	count1 := 0
	count2 := 0
	candidate1 := 0
	candidate2 := 0

	for loop := 0; loop < length; loop++ {
		if candidate1 == nums[loop] {
			count1++
		} else if candidate2 == nums[loop] {
			count2++
		} else if count1 == 0 {
			candidate1 = nums[loop]
			count1++
		} else if count2 == 0 {
			candidate2 = nums[loop]
			count2++
		} else {
			count1--
			count2--
		}
	}

	c1 := 0
	c2 := 0
	for loop := 0; loop < length; loop++ {
		if count1 > 0 && candidate1 == nums[loop] {
			c1++
		}
		if count2 > 0 && candidate2 == nums[loop] {
			c2++
		}
	}
	if c1 > time {
		result = append(result, candidate1)
	}

	if c2 > time {
		result = append(result, candidate2)
	}
	return result
}

func main() {
	input := []int{2, 2, 1, 3}
	majorityElement(input)
}
