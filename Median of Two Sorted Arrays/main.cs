/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

public class Solution
{
    public double FindMedianSortedArrays(int[] nums1, int[] nums2)
    {
        int index = nums1.Length / 2;
        int l = 0;
        int r = nums1.Length / 2;
        while (l >= r)
        {
            int mid = l + (r - l) / 2;
            if (nums2[mid] == nums1[index]) break;
            if (nums2[mid] > nums1[index]) r = mid - 1;
            if (nums2[mid] < nums1[index]) l = mid + 1;
        }

        int pivot = l + (r - l) / 2;
        int v = index + (nums2.Length - pivot) / 2 - pivot / 2;
        int d = index > v ? 1 : -1;
        int time = index;
        int time1 = 0;
        int time2 = 0;
        double m1 = nums1[index];
        while (time != v)
        {
            int sign = nums1[index + time1 * d] - nums2[pivot + time2 * d];
            if (sign == d || sign == 0)
            {
                time2++;
                m1 = nums2[index + time2 * d];
            }
            else {
                time1++;
                m1 = nums1[index = time1 * d];
            }
            time += d;
        }

        if ((nums1.Length + nums2.Length) % 2 == 0)
        {
            double m2 = 0;

            int sign = nums1[index + time1 * d] - nums2[pivot + time2 * d];
            if (sign == d || sign == 0)
            {
                m2 = nums2[pivot + (time2 + 1) * d];
            }
            else 
                m2 = nums1[index + (time1 + 1) * d];   
            return (m1 + m2) / 2;
        } 

        return m1;
    }
}