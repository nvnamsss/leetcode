/*
You are given several boxes with different colors represented by different positive numbers.

You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.

Return the maximum points you can get.

 

Example 1:

Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
Example 2:

Input: boxes = [1,1,1]
Output: 9
Example 3:

Input: boxes = [1]
Output: 1
 

Constraints:

1 <= boxes.length <= 100
1 <= boxes[i] <= 100*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> values;
    int memo[105][105][105];
    int dp(vector<int> &boxes, int l, int r, int k)
    {
        if (l > r)
            return 0;

        if (memo[l][r][k] != 0)
            return memo[l][r][k];
        // while ((l + 1) <= r && boxes[l] == boxes[l + 1])
        // {
        //     l++;
        //     k++;
        // }

        int rs = dp(boxes, l + 1, r, 0) + (k + 1) * (k + 1);

        for (int i = l + 1; i <= r; i++)
        {
            if (boxes[l] == boxes[i])
            {
                rs = max(rs, dp(boxes, i, r, k + 1) + dp(boxes, l + 1, i - 1, 0));
            }
        }

        memo[l][r][k] = rs;
        return rs;
    }


public:
    int removeBoxes(vector<int> &boxes)
    {
        memset(memo, 0, sizeof(memo));
        return dp(boxes, 0, boxes.size() - 1, 0);
    }
};

int main()
{
    vector<int> boxes = vector<int>{1, 3, 2, 2, 2, 3, 4, 3, 1};
    Solution s;
    int rs = s.removeBoxes(boxes);
    cout << "Result: " << rs << endl;
}