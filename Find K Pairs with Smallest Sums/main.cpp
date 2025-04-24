/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.



Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]


Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in ascending order.
1 <= k <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Comparer
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second >= b.second;
        }
        return a.first > b.first;
    }

    bool operator()(Record &a, Record &b)
    {
        if (a.sum == b.sum)
        {
            return a.i1 >= b.i2;
        }
        return a.sum > b.sum;
    }
};

struct Record
{
    int sum;
    int i1;
    int i2;
    int times;

    Record(int sum, int i1, int i2, int dup = 1)
    {
        this->sum = sum;
        this->i1 = i1;
        this->i2 = i2;
        this->times = dup;
    }
};

class Solution
{
    int binarySearch(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] <= target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return l;
    }

    int binarySearchExact(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return l;
    }

public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;
        priority_queue<Record, vector<Record>, Comparer> pq;

        for (int i = 0; i < nums1.size(); i++)
        {
            Record r = Record(nums1[i] + nums2[0], i, 0);
            pq.push(r);
        }

        while (k > 0 && !pq.empty())
        {
            Record t1 = pq.top();
            pq.pop();
            Record t2 = pq.top();

            // find current pivot
            int currentPivot = t1.i2;
            // find next pivot;
            int nextPivot = binarySearch(nums2, t2.sum - nums1[t1.i1]);

            // calculate k
            int target = min(currentPivot + k, nextPivot);
            k -= (nextPivot - currentPivot);
            for (int i = currentPivot; i < target; i++)
            {
                ans.push_back({nums1[t1.i1], nums2[i]});
            }

            if (nextPivot < nums2.size())
            {
                Record r = Record(nums1[t1.i1] + nums2[nextPivot], t1.i1, nextPivot);
                pq.push(r);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};

    s.kSmallestPairs(nums1, nums2, 3);

    nums1 = {1, 1, 2};
    nums2 = {1, 2, 3};
    s.kSmallestPairs(nums1, nums2, 2);

    nums1 = {1, 2};
    nums2 = {3};
    s.kSmallestPairs(nums1, nums2, 3);
}