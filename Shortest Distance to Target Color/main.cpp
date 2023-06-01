/*
You are given an array colors, in which there are three colors: 1, 2 and 3.

You are also given some queries. Each query consists of two integers i and c, return the shortest distance between the given index i and the target color c. If there is no solution return -1.



Example 1:

Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
Output: [3,0,3]
Explanation:
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).
Example 2:

Input: colors = [1,2], queries = [[0,3]]
Output: [-1]
Explanation: There is no 3 in the array.


Constraints:

1 <= colors.length <= 5*10^4
1 <= colors[i] <= 3
1 <= queries.length <= 5*10^4
queries[i].length == 2
0 <= queries[i][0] < colors.length
1 <= queries[i][1] <= 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int searchUpper(vector<int> &arr, int target)
    {
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (arr[m] == target)
            {
                return m;
            }
            else if (arr[m] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
    int searchLower(vector<int> &arr, int target)
    {
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (arr[m] == target)
            {
                return m;
            }
            else if (arr[m] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return r;
    }
    vector<int> binarySearch(vector<int> &colors, vector<vector<int>> &queries)
    {
        vector<int> ans;
        vector<vector<int>> locations = vector<vector<int>>(3, vector<int>());
        for (int i = 0; i < colors.size(); i++)
        {
            locations[colors[i] - 1].push_back(i);
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int location = queries[i][0];
            int color = queries[i][1] - 1;

            int upper = searchUpper(locations[color], location);
            int lower = searchLower(locations[color], location);

            upper = upper >= locations[color].size() ? -1 : abs(locations[color][upper] - location);
            lower = lower < 0 ? -1 : abs(locations[color][lower] - location);
            // cout << upper << "-" << lower << endl;
            int value = -1;
            if (upper == -1)
            {
                value = lower;
            }
            else if (lower == -1)
            {
                value = upper;
            }
            else
            {
                value = min(upper, lower);
            }

            ans.push_back(value);
        }

        return ans;
    }

    vector<int> twoPass(vector<int> &colors, vector<vector<int>> &queries)
    {
        vector<int> ans = vector<int>(queries.size(), -1);
        vector<vector<int>> closest = vector<vector<int>>(colors.size(), vector<int>(3, -1));
        vector<int> locations = vector<int>(3, -1);
        for (int i = 0; i < colors.size(); i++)
        {
            locations[colors[i] - 1] = i;
            for (int j = 0; j < 3; j++)
            {
                if (locations[j] != -1)
                {
                    int dif = abs(i - locations[j]);
                    if (closest[i][j] == -1) {
                        closest[i][j] = dif;
                    }
                    closest[i][j] = min(closest[i][j], dif);
                }
            }
        }

        for (int i = 0; i < 3; i++)
        {
            locations[i] = -1;
        }

        for (int i = colors.size() - 1; i >= 0; i--)
        {
            locations[colors[i] - 1] = i;
            for (int j = 0; j < 3; j++)
            {
                if (locations[j] != -1)
                {
                    int dif = abs(i - locations[j]);
                    if (closest[i][j] == -1) {
                        closest[i][j] = dif;
                    }
                    closest[i][j] = min(closest[i][j], dif);
                }
            }
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int location = queries[i][0];
            int color = queries[i][1] - 1;
            ans[i] = closest[location][color];
        }
        
        return ans;
    }

public:
    vector<int> shortestDistanceColor(vector<int> &colors, vector<vector<int>> &queries)
    {
        return twoPass(colors, queries);
    }
};

void print(vector<int>& ans) {
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " "; 
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<int> colors = {1,1,2,1,3,2,2,3,3};
    vector<vector<int>> queries = {{1,3},{2,2},{6,1}};
    vector<int> ans = s.shortestDistanceColor(colors, queries);
    print(ans);
}