#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int partition(vector<int> &nums, int low, int high, int pivotIndex)
    {
        if (low == high)
        {
            return low;
        }
        int pivot = nums[pivotIndex];
        int storeIndex = low;
        swap(nums[high], nums[pivotIndex]);

        for (int i = low; i <= high; i++)
        {
            if (nums[i] > pivot)
            {
                swap(nums[i], nums[storeIndex]);
                storeIndex++;
            }
        }
        swap(nums[storeIndex], nums[high]);
        return storeIndex;
    }

    void print(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    int quickSelect(vector<int> &nums, int k)
    {
        int l = 0;
        int r = nums.size() - 1;
        int pivot = 0;
        do
        {
            pivot = l + (r - l) / 2;
            pivot = partition(nums, l, r, pivot);
            if (pivot > k)
            {
                r = pivot - 1;
            }
            else
            {
                l = pivot + 1;
            }
        } while (pivot != k);
        print(nums);
        return nums[k];
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSelect(nums, k - 1);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 2, 1, 6, 7, 4, 16, 14, 15, 11, 12, 10};
    cout << s.findKthLargest(nums, 2) << endl;
}