#include <bits/stdc++.h>
using namespace std;

class MedianDutchQuicksort {
    vector<int> partition(vector<int>& nums, int low, int high) {
        
    }
    public:
};

class Quicksort
{
    int partition(vector<int> &nums, int low, int high) {
        int midStart = low;
        // int midEnd = low + (high - low) / 2;
        int mid = low + (high - low) / 2;
        int median = findMedian(nums, low, mid, high);
        swap(nums[median], nums[low]);
        int pivot = nums[low];
        int i = low + 1;
        int j = high;
        while (true) {
            while (i <= j && nums[i] <= pivot) {
                i++;
            }

            while (i <= j && nums[j] >= pivot) {
                j--;
            }

            if (i > j) {
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);

        return j;
    }

    int findMedian(vector<int>& nums, int low, int mid, int high) {
        if (nums[low] < nums[mid]) {
            if (nums[mid] < nums[high]) {
                return mid;
            } else if (nums[low] < nums[high]) {
                return high;
            } else {
                return low;
            }
        } else {
            if (nums[mid] < nums[high]) {
                return high;
            } else if (nums[low] < nums[high]) {
                return low;
            } else {
                return mid;
            }
        }
    }
public:
    void sort(vector<int> &nums, int low, int high)
    {
        if (low < high) {
            int pivot = partition(nums, low, high);
            sort(nums, low, pivot - 1);
            sort(nums, pivot + 1, high);
        }
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
    Quicksort q;
    vector<int> nums = {7, 1, 2, 5, 7, 9, 2, 4, 5, 7, 12, 5, 7, 7, 7, 402, 123, 41516, 12, 34166};
    q.sort(nums, 0, nums.size() - 1);

    print(nums);
}