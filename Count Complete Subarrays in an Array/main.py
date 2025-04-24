from typing import List, Dict


class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        """
        Count the number of complete subarrays in nums.
        A subarray is complete if it contains all distinct elements from the original array.
        """
        m: Dict[int, int] = {}
        mp: Dict[int, int] = {}
        
        for i in range(len(nums)):
            m[nums[i]] = m.get(nums[i], 0) + 1
        
        l = 0
        r = 0
        prev_l = 0
        ans = 0

        while r < len(nums):
            mp[nums[r]] = mp.get(nums[r], 0) + 1
            if len(mp) == len(m):
                
                while len(mp) == len(m):
                    mp[nums[l]] -= 1
                    if mp[nums[l]] == 0:
                        del mp[nums[l]]
                    l += 1
                
                ans += (l - prev_l) * (len(nums) - r)
                prev_l = l
            r += 1

        return ans
