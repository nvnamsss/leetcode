package main

import (
	"sort"
)

/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [], target = 0
Output: []


Constraints:

0 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func kSum(nums []int, target, start, k int) [][]int {
	rs := [][]int{}
	n := len(nums)

	if start == n || nums[start]*k > target || target > nums[n-1]*k {
		return rs
	}

	if k == 2 {
		return twoSum(nums, target, start)
	}
	for loop := start; loop < n; loop++ {
		if loop == start || nums[loop-1] != nums[loop] {
			sub := kSum(nums, target-nums[loop], loop+1, k-1)
			for _, s := range sub {
				rs = append(rs, []int{nums[loop]})
				rs[len(rs)-1] = append(rs[len(rs)-1], s...)
			}
		}
	}
	return rs
}

func twoSum(nums []int, target int, start int) [][]int {
	rs := [][]int{}
	n := len(nums)
	lo := start
	hi := n - 1
	for lo < hi {
		sum := nums[lo] + nums[hi]
		if sum == target {
			rs = append(rs, []int{nums[lo], nums[hi]})
		}

		if sum < target || (lo > start && nums[lo] == nums[lo-1]) {
			lo++
		} else if sum > target || hi < n-1 && nums[hi] == nums[hi+1] {
			hi--
		} else {
			rs = append(rs, []int{nums[lo], nums[hi]})
			lo++
			hi--
		}
	}

	return rs
}

func fourSum(nums []int, target int) [][]int {
	sort.Slice(nums, func(i, j int) bool { return nums[i] < nums[j] })

	return kSum(nums, target, 0, 4)
}
