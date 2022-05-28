#include <bits/stdc++.h>
using namespace std;

class Solution
{
    double Olognpm(vector<int> &nums1, vector<int> &nums2)
    {
        
        return 0;
    }

    double On(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int c = 0;
        int mid = (m + n) / 2;
        int i1 = 0;
        int i2 = 0;
        int i = 0;
        int size = 2 - (m + n) % 2;
        vector<int> vs = vector<int>(size);
        while (c < mid + 1)
        {
            if (i1 == m)
            {
                vs[i] = nums2[i2];
                i2++;
            }
            else if (i2 == n)
            {
                vs[i] = nums1[i1];
                i1++;
            }
            else if (nums1[i1] < nums2[i2])
            {
                vs[i] = nums1[i1];
                i1++;
            }
            else
            {
                vs[i] = nums2[i2];
                i2++;
            }
            i = (i + 1) % size;
            c++;
        }
        int sum = 0;
        for (int i = 0; i < vs.size(); i++)
        {
            sum += vs[i];
        }
        return sum / (double)size;
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        return On(nums1, nums2);
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 3};
    nums2 = {2, 4};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 3};
    nums2 = {2, 4, 5};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}