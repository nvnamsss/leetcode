# The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

# For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
# Given an array nums, return the sum of all XOR totals for every subset of nums. 

# Note: Subsets with the same elements should be counted multiple times.

# An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

 

# Example 1:

# Input: nums = [1,3]
# Output: 6
# Explanation: The 4 subsets of [1,3] are:
# - The empty subset has an XOR total of 0.
# - [1] has an XOR total of 1.
# - [3] has an XOR total of 3.
# - [1,3] has an XOR total of 1 XOR 3 = 2.
# 0 + 1 + 3 + 2 = 6
# Example 2:

# Input: nums = [5,1,6]
# Output: 28
# Explanation: The 8 subsets of [5,1,6] are:
# - The empty subset has an XOR total of 0.
# - [5] has an XOR total of 5.
# - [1] has an XOR total of 1.
# - [6] has an XOR total of 6.
# - [5,1] has an XOR total of 5 XOR 1 = 4.
# - [5,6] has an XOR total of 5 XOR 6 = 3.
# - [1,6] has an XOR total of 1 XOR 6 = 7.
# - [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
# 0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
# Example 3:

# Input: nums = [3,4,5,6,7,8]
# Output: 480
# Explanation: The sum of all XOR totals for every subset is 480.
 

# Constraints:

# 1 <= nums.length <= 12
# 1 <= nums[i] <= 20

from typing import List


class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        # create a list with len(nums) + 1
        # all elements are 0
        prefix = [0] * (len(nums) + 1)
        for i in range(len(nums)):
            # for each element in nums
            # set prefix[i + 1] to the xor of prefix[i] and nums[i]
            prefix[i + 1] = prefix[i] ^ nums[i]
        
        result = 0

        for i in range(len(nums)):
            print(f"prefix[{i}] = {prefix[i]}")
            # for each element in prefix
            # set result to the xor of result and prefix[i]
            for j in range(i + 1):
                # for each element in prefix
                # set result to the xor of result and prefix[j]
                # print(f"prefix[{i}] = {prefix[i]}, prefix[{j}] = {prefix[j]}")
                result += prefix[i + 1] ^ prefix[j]
        return result

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Test Case 1: Example 1 from the problem
    nums1 = [1, 3]
    expected1 = 6
    result1 = solution.subsetXORSum(nums1)
    print(f"Test Case 1: nums = {nums1}")
    print(f"Expected: {expected1}, Got: {result1}")
    print(f"Test Result: {'Pass' if expected1 == result1 else 'Fail'}")
    print()
    
    # Test Case 2: Example 2 from the problem
    nums2 = [5, 1, 6]
    expected2 = 28
    result2 = solution.subsetXORSum(nums2)
    print(f"Test Case 2: nums = {nums2}")
    print(f"Expected: {expected2}, Got: {result2}")
    print(f"Test Result: {'Pass' if expected2 == result2 else 'Fail'}")
    print()
    
    # Test Case 3: Example 3 from the problem
    nums3 = [3, 4, 5, 6, 7, 8]
    expected3 = 480
    result3 = solution.subsetXORSum(nums3)
    print(f"Test Case 3: nums = {nums3}")
    print(f"Expected: {expected3}, Got: {result3}")
    print(f"Test Result: {'Pass' if expected3 == result3 else 'Fail'}")
    print()
    
    # Test Case 4: Single element array
    nums4 = [10]
    expected4 = 10
    result4 = solution.subsetXORSum(nums4)
    print(f"Test Case 4: nums = {nums4}")
    print(f"Expected: {expected4}, Got: {result4}")
    print(f"Test Result: {'Pass' if expected4 == result4 else 'Fail'}")
    print()
    
    # Test Case 5: Array with identical elements
    nums5 = [2, 2, 2]
    expected5 = 6
    result5 = solution.subsetXORSum(nums5)
    print(f"Test Case 5: nums = {nums5}")
    print(f"Expected: {expected5}, Got: {result5}")
    print(f"Test Result: {'Pass' if expected5 == result5 else 'Fail'}")