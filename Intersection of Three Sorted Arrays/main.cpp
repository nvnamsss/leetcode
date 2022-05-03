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
