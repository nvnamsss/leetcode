/*
Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.



Example 1:

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.
Example 2:

Input: arr1 = [197,418,523,876,1356], arr2 = [501,880,1593,1710,1870], arr3 = [521,682,1337,1395,1764]
Output: []


Constraints:

1 <= arr1.length, arr2.length, arr3.length <= 1000
1 <= arr1[i], arr2[i], arr3[i] <= 2000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
    {
        int i1 = 0;
        int i2 = 0;
        int i3 = 0;
        int l1 = arr1.size();
        int l2 = arr1.size();
        int l3 = arr1.size();
        vector<int> ans;
        while (i1 < l1 && i2 < l2 && i3 < l3)
        {
            if (arr1[i1] == arr2[i2] && arr1[i1] == arr3[i3])
            {
                ans.push_back(arr1[i1]);
                i1++;
                i2++;
                i3++;
                continue;
            }

            if (arr1[i1] < arr2[i2] || arr1[i1] < arr3[i3])
            {
                i1++;
                continue;
            }

            if (arr2[i2] < arr1[i1] || arr2[i2] < arr3[i3])
            {
                i2++;
                continue;
            }

            if (arr3[i3] < arr1[i1] || arr3[i3] < arr2[i2])
            {
                i3++;
                continue;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 5, 7, 9};
    vector<int> arr3 = {1, 3, 4, 5, 8};
    s.arraysIntersection(arr1, arr2, arr3);
}