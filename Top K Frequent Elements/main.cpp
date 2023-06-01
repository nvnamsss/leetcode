/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> values;
    unordered_map<int, int> m;

    int partition(int left, int right, int pivot)
    {
        int pivotFreq = m[values[pivot]];
        swap(values[right], values[pivot]);
        int storeIndex = left;
        for (int i = left; i <= right; i++)
        {
            if (m[values[i]] > pivotFreq)
            {
                swap(values[i], values[storeIndex]);
                storeIndex++;
            }
        }
        swap(values[right], values[storeIndex]);
        return storeIndex;
    }

    void quickSelect(int left, int right, int k)
    {
        if (left == right)
            return;

        int pivot_index = left + rand() % (right - left + 1);
        pivot_index = partition(left, right, pivot_index);
        if (k == pivot_index)
        {
            return;
        }
        else if (k < pivot_index)
        {
            quickSelect(left, pivot_index - 1, k);
        }
        else
        {
            quickSelect(pivot_index + 1, right, k);
        }
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        values = {};
        m = {};
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        vector<int> rs;
        for (auto &&v : m)
        {
            values.push_back(v.first);
        }
        quickSelect(0, values.size() - 1, k);
        for (int i = 0; i < k; i++)
        {
            rs.push_back(values[i]);
        }

        return rs;
    }
};

void log(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    Solution s;
    vector<int> nums = {1, 2};
    vector<int> rs = s.topKFrequent(nums, 2);
    log(rs);

    nums = {1, 1, 1, 1, 2, 2, 2, 3, 3};
    rs = s.topKFrequent(nums, 2);
    log(rs);

    nums = {4, 1, -1, 2, -1, 2, 3};
    rs = s.topKFrequent(nums, 2);
    log(rs);
    nums = {1, 1, 1, 2, 2, 3333};
    rs = s.topKFrequent(nums, 2);
    log(rs);
    nums = {3, 0, 1, 0};
    rs = s.topKFrequent(nums, 1);
    log(rs);
}