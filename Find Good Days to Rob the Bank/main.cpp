/*
You and a gang of thieves are planning on robbing a bank. You are given a 0-indexed integer array security, where security[i] is the number of guards on duty on the ith day. The days are numbered starting from 0. You are also given an integer time.

The ith day is a good day to rob the bank if:

There are at least time days before and after the ith day,
The number of guards at the bank for the time days before i are non-increasing, and
The number of guards at the bank for the time days after i are non-decreasing.
More formally, this means day i is a good day to rob the bank if and only if security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].

Return a list of all days (0-indexed) that are good days to rob the bank. The order that the days are returned in does not matter.

 

Example 1:

Input: security = [5,3,3,3,5,6,2], time = 2
Output: [2,3]
Explanation:
On day 2, we have security[0] >= security[1] >= security[2] <= security[3] <= security[4].
On day 3, we have security[1] >= security[2] >= security[3] <= security[4] <= security[5].
No other days satisfy this condition, so days 2 and 3 are the only good days to rob the bank.
Example 2:

Input: security = [1,1,1,1,1], time = 0
Output: [0,1,2,3,4]
Explanation:
Since time equals 0, every day is a good day to rob the bank, so return every day.
Example 3:

Input: security = [1,2,3,4,5,6], time = 2
Output: []
Explanation:
No day has 2 days before it that have a non-increasing number of guards.
Thus, no day is a good day to rob the bank, so return an empty list.
Example 4:

Input: security = [1], time = 5
Output: []
Explanation:
No day has 5 days before and after it.
Thus, no day is a good day to rob the bank, so return an empty list.
 

Constraints:

1 <= security.length <= 105
0 <= security[i], time <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        queue<int> incr;
        queue<int> decr;
        vector<int> ans;

        for (int i = 0; i < security.size() - 1; i++)
        {
            if (security[i] < security[i + 1])
            {
                incr.push(i + 1);
            }

            if (security[i] > security[i + 1])
            {
                decr.push(i + 1);
            }
        }

        int from = time;
        int to = security.size() - time;
        for (int i = from; i < to; i++)
        {
            while (!incr.empty() && incr.front() < i - time)
            {
                incr.pop();
            }

            while (!decr.empty() && decr.front() < i)
            {
                decr.pop();
            }

            if ((incr.empty() || (incr.front() < i && incr.front() >= i - time)) &&
             (decr.empty() || decr.front() > i + time))
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

void print(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    Solution s;
    vector<int> security = {5, 3, 3, 3, 5, 6, 2};
    vector<int> rs = s.goodDaysToRobBank(security, 2);
    print(rs);

    security = {1, 1, 1, 1, 1};
    rs = s.goodDaysToRobBank(security, 0);
    print(rs);

    security = {1, 2, 3, 4};
    rs = s.goodDaysToRobBank(security, 0);
    print(rs);

    security = {1};
    rs = s.goodDaysToRobBank(security, 5);
    print(rs);

    security = {1, 2, 3, 4, 5, 6};
    rs = s.goodDaysToRobBank(security, 2);
    print(rs);

    security = {1, 2, 3, 4};
    rs = s.goodDaysToRobBank(security, 1);
    print(rs);
}