/*
There are n tasks assigned to you. The task times are represented as an integer array tasks of length n, where the ith task takes tasks[i] hours to finish. A work session is when you work for at most sessionTime consecutive hours and then take a break.

You should finish the given tasks in a way that satisfies the following conditions:

If you start a task in a work session, you must complete it in the same work session.
You can start a new task immediately after finishing the previous one.
You may complete the tasks in any order.
Given tasks and sessionTime, return the minimum number of work sessions needed to finish all the tasks following the conditions above.

The tests are generated such that sessionTime is greater than or equal to the maximum element in tasks[i].

 

Example 1:

Input: tasks = [1,2,3], sessionTime = 3
Output: 2
Explanation: You can finish the tasks in two work sessions.
- First work session: finish the first and the second tasks in 1 + 2 = 3 hours.
- Second work session: finish the third task in 3 hours.
Example 2:

Input: tasks = [3,1,3,1,1], sessionTime = 8
Output: 2
Explanation: You can finish the tasks in two work sessions.
- First work session: finish all the tasks except the last one in 3 + 1 + 3 + 1 = 8 hours.
- Second work session: finish the last task in 1 hour.
Example 3:

Input: tasks = [1,2,3,4,5], sessionTime = 15
Output: 1
Explanation: You can finish all the tasks in one work session.
 

Constraints:

n == tasks.length
1 <= n <= 14
1 <= tasks[i] <= 10
max(tasks[i]) <= sessionTime <= 15
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
        vector<int> sessions;
    unordered_map<string , int> dp;
    
    string encodeState(int pos, vector<int>& sessions) {
        vector<int> copy = sessions;
        sort(copy.begin(), copy.end());
        
        string key = to_string(pos) + "$";
        for (int i = 0; i < copy.size(); i++)
            key += to_string(copy[i]) + "$";
        
        return key;
    }
    
    int solve(vector<int>& tasks, int n, int sessionTime, int pos) {
        if (pos >= n )
            return 0;
        
        string key = encodeState(pos, sessions);
        
        if (dp.find(key) != dp.end())
            return dp[key];
        
        sessions.push_back(tasks[pos]);
        int ans = 1 + solve(tasks, n, sessionTime, pos + 1);
        sessions.pop_back();
        
        for (int i = 0; i < sessions.size();i++) {
            if (sessions[i] + tasks[pos] <= sessionTime) {
                sessions[i] += tasks[pos];
                ans = min(ans, solve(tasks, n, sessionTime, pos + 1));
                sessions[i] -= tasks[pos];
            }
        }
        
        return dp[key] = ans;
    }

public:
    int minSessions(vector<int> &tasks, int sessionTime)
    {
        return solve(tasks, tasks.size(), sessionTime, 0);
    }
};

int main(){
    Solution s;
    vector<int> tasks=vector<int>{
        1,5,7,10,3,8,4,2,6,2
    };
    s.minSessions(tasks, 10);
}