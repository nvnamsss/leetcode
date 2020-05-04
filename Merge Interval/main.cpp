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

    int partition(vector<vector<int>> &arr, int low, int high)
    {
        int pivot = arr[high][0];

        int i = (low - 1); // Index of smaller element

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j][0] < pivot)
            {
                i++; // increment index of smaller element

                vector<int> tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

        vector<int> tmp = arr[i +1];
        arr[i + 1] = arr[high];
        arr[high] = tmp;
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
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        result = vector<vector<int>>();
        int length = intervals.size();
        quickSort(intervals, 0, length - 1);
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

                // if (lupper <= llower)
                // {
                //     llower = min(ilower, llower);
                //     lupper = max(iupper, lupper);

                //     done = false;
                // }

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