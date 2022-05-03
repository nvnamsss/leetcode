/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].



Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int offset = 1e4;
        // implement segment tree
    void update(int index, int value, vector<int>& tree, int size) {
        index += size;  // shift the index to the leaf
        // update from leaf to root
        tree[index] += value;
        while (index > 1) {
            index /= 2;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }
    
    void updateTree(vector<int> &tree, int index, int value, int size)
    {
        // set value at position p
        index = index + size;  
        tree[index] += value;

        // move upward and update parents
        for (int i = index; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    // function to get sum on interval [l, r)
    int query(vector<int> &tree, int l, int r)
    {
        int res = 0;
        
        // loop to find the sum in the range
        for (l += offset, r += offset; l < r; l >>= 1, r >>= 1)
        {
            if (l&1)
                res += tree[l++];
        
            if (r&1)
                res += tree[--r];
        }
        
        return res;
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> segmentTree = vector<int>(2 * offset + 1, 0);
        vector<int> ans = vector<int>(nums.size(), 0);
        int size = offset * 2;
        // build segment tree
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int v = query(segmentTree, 0, nums[i] + offset);
            ans[i] = v;
            updateTree(segmentTree, i, 1, size);
        }

        return ans;
    }
};

void print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
int main()
{
    Solution s;
    vector<int> nums = {5, 2, 6, 1};
    vector<int> ans = s.countSmaller(nums);
    print(ans);

    nums = {-1};
    ans = s.countSmaller(nums);
    print(ans);

    nums = {-1, -1};
    ans = s.countSmaller(nums);
    print(ans);

    nums = {-1, -1, -1, -1, -1, -2, -3};
    ans = s.countSmaller(nums);
    print(ans);
}