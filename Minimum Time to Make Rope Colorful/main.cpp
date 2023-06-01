/*
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.



Example 1:


Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
Example 2:


Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
Example 3:


Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the ballons at indices 0 and 4. Each ballon takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.


Constraints:

n == colors.length == neededTime.length
1 <= n <= 105
1 <= neededTime[i] <= 104
colors contains only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Comparer
{

public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
class Solution
{
    int minCostPQ(string colors, vector<int> &neededTime)
    {
        int ans = 0;
        for (int i = 0; i < colors.size(); i++)
        {
            int j = i;
            priority_queue<int, vector<int>, Comparer> pq;
            while (j < colors.size() && colors[j] == colors[i])
            {
                pq.push(neededTime[j]);
                j++;
            }

            while (pq.size() > 1)
            {
                int t = pq.top();
                ans += t;
                pq.pop();
                i++;
            }
        }

        return ans;
    }

    int minCostSum(string colors, vector<int> &neededTime)
    {
        int ans = 0;
        for (int i = 0; i < colors.size(); i++)
        {
            int j = i;
            int sum = 0;
            int m = 0;
            priority_queue<int, vector<int>, Comparer> pq;
            while (j < colors.size() && colors[j] == colors[i])
            {
                sum += neededTime[j];
                m = max(m, neededTime[j]);
                j++;
            }

            if (j - i > 1) {
                ans += sum - m;
                i = j - 1;
            }
        }

        return ans;
    }
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        return minCostSum(colors, neededTime);
    }
};

int main()
{
    Solution s;
    string c = "abaac";
    vector<int> times = {1, 2, 3, 4, 5};
    cout << s.minCost(c, times) << endl;

    c = "bbbaaa";
    times = {4,9,3,8,8,9};
    cout << s.minCost(c, times) << endl;

}