/*
(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.



Example 1:

Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
Example 2:

Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.


Constraints:

3 <= mountain_arr.length() <= 104
0 <= target <= 109
0 <= mountain_arr.get(index) <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
    int findPeak(MountainArray& arr) {
        int l = 0;
        int r = arr.length() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            bool increase = (m > 0 && arr.get(m) > arr.get(m - 1)) || (m < arr.length() - 1 && arr.get(m) < arr.get(m + 1));
            if (increase) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }

    int searchAsc(MountainArray& arr, int l, int r, int target) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            int v = arr.get(m);
            if (v == target) {
                return m;
            } else if (v < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }

    int searchDesc(MountainArray& arr, int l, int r, int target) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            int v = arr.get(m);
            if (v == target) {
                return m;
            } else if (v > target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int peak = findPeak(mountainArr);
        int ans = searchDesc(mountainArr, 0, peak, target);
        if (ans != -1) {
            return ans;
        }

        return searchAsc(mountainArr, peak, mountainArr.length() - 1, target);
    }
};