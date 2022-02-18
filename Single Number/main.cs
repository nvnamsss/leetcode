public class Solution {
    public int SingleNumber(int[] nums) {
        int sum = 0;
        for (int loop = 0; loop < nums.Length; loop++)
        {
            sum ^= nums[loop];
        }

        return sum;
    }
}