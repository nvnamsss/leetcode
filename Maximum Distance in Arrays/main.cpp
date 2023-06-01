/*
You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.



Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0


Constraints:

m == arrays.length
2 <= m <= 105
1 <= arrays[i].length <= 500
-104 <= arrays[i][j] <= 104
arrays[i] is sorted in ascending order.
There will be at most 105 integers in all the arrays.
*/

#include <bits/stdc++.h>
using namespace std;

class Greater
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return a[0] > b[0];
    }
};

class Greater2
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        priority_queue<vector<int>> pqMin;
        priority_queue<vector<int>, vector<vector<int>>, Greater> pqMax;

        for (int i = 0; i < arrays.size(); i++)
        {
            int minimum = INT32_MAX;
            int maximum = INT32_MIN;

            for (int j = 0; j < arrays[i].size(); j++)
            {
                minimum = min(minimum, arrays[i][j]);
                maximum = max(maximum, arrays[i][j]);
            }

            pqMin.push({minimum, i});
            pqMax.push({maximum, i});

            while (pqMin.size() > 2)
            {
                pqMin.pop();
            }

            while (pqMax.size() > 2)
            {
                pqMax.pop();
            }
        }

        vector<int> secondMin = pqMin.top();
        vector<int> secondMax = pqMax.top();
        pqMin.pop();
        pqMax.pop();
        vector<int> minimum = pqMin.top();
        vector<int> maximum = pqMax.top();

        if (minimum[1] == maximum[1])
        {
            return max(abs(maximum[0] - secondMin[0]), abs(secondMax[0] - minimum[0]));
        }

        return abs(maximum[0] - minimum[0]);
    }
};

int main()
{
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    cout << pq.top() << endl;

    Solution s;
    vector<vector<int>> arrays = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    cout << s.maxDistance(arrays) << endl;
}