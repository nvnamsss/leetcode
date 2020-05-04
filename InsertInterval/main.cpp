#include <iostream>
#include <vector>
#include <math>
using namespace std;

class Solution
{
private:
    vector<vector<int>> result;
    int min(int a, int b)
    {
        return a < b ? a : b;
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    void removeMiddle(int lower, int upper)
    {
        int length = result.size();
        for (int loop = length - 2; loop >= 0; loop--)
        {
            int llower = result[loop][0];
            int lupper = result[loop][1];
            cout << lower << " " << upper << endl;

            if (lower <= llower && upper >= lupper)
            {
                result.erase(result.begin() + loop);
                loop++;
            }
            /* code */
        }
    }

    void swap(vector<vector<int>> &arr, int a, int b)
    {

        vector<int> tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    int partition(vector<vector<int>> &arr, int low, int high)
    {
        int pivot = arr[high][0];

        int i = (low - 1); // Index of smaller element

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j][0] < pivot)
            {
                i++; // increment index of smaller element

                swap(arr, i, j);
            }
        }

        swap(arr, i + 1, high);

        return (i + 1);
    }

    void quickSort(vector<vector<int>> &arr, int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[pi] is now
           at right place */
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);  // Before pi
            quickSort(arr, pi + 1, high); // After pi
        }

        // cout << "after sort: ";
        // for (int loop = 0; loop < arr.size(); loop++)
        // {
        //     cout << arr[loop][0]  << " ";
        // }
        // cout << endl;
    }

    int binarySearch(vector<vector<int>> &arr, int left, int right, vector<int> &newInterval)
    {
        if (right >= left)
        {
            int mid = (right + left) / 2;

            if (arr[mid][0] == newInterval[0])
            {
                return mid;
            }

            if (arr[mid][0] > newInterval[0])
            {
                return binarySearch(arr, left, mid - 1, newInterval);
            }

            return binarySearch(arr, mid + 1, right, newInterval);
        }

        return left;
    }

    void binaryInsert(vector<vector<int>> &arr, vector<int> &newInterval)
    {
        int index = binarySearch(arr, 0, arr.size() - 1, newInterval);
        cout << "binary search " << index << endl;
        arr.insert(arr.begin() + index, newInterval);

                cout << "after sort: ";
        for (int loop = 0; loop  arr.size(); loop++)
        {
            cout << arr[loop][0]  << " ";
        }
        cout << endl;
    }

public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        result = vector<vector<int>>();
        // cout << intervals.size() << endl;
        // intervals.push_back(newInterval);
        int length = intervals.size();
        
        binaryInsert(intervals, newInterval);
        cout << intervals.size() << endl;
        // quickSort(intervals, 0, intervals.size() - 1);
        for (int loop = 0; loop < length; loop++)
        {
            int llower = intervals[loop][0];
            int lupper = intervals[loop][1];
            int index = loop + 1;

            while (index < length)
            {
                int ilower = intervals[index][0];
                int iupper = intervals[index][1];
                bool done = true;

                if (ilower <= lupper && iupper >= llower)
                {
                    llower = min(ilower, llower);
                    lupper = max(iupper, lupper);
                    done = false;
                }

                if (done)
                    break;

                index += 1;
            }

            loop = index - 1;
            result.push_back(vector<int>{llower, lupper});
        }

        return result;
    }
};