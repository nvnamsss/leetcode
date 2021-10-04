using System;
public class Solution {
    public int Trap(int[] height) {
        int left = 0;
        int right = height.Length - 1;
        int leftmax = 0;
        int rightmax = 0;
        int trapped = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftmax) {
                    leftmax = height[left];
                } else {
                    trapped += leftmax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightmax) {
                    rightmax = height[right];
                } else {
                    trapped += rightmax - height[right];
                }
                right--;
            }
        }
        return trapped;
    }
}