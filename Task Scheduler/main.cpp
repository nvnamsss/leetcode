/*
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.



Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation:
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation:
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A


Constraints:

1 <= task.length <= 104
tasks[i] is upper-case English letter.
The integer n is in the range [0, 100].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < tasks.size(); i++)
        {
            m[tasks[i]]++;
        }
        int task = m.size();
        priority_queue<pair<int, char>> pq;
        for (auto &&it : m)
        {
            pq.push({it.second, it.first});
        }

        int ans = 0;
        queue<pair<int, char>> q;
        while (task > 0)
        {
            while (!q.empty() && q.front().first <= ans)
            {
                pair<int, char> p = q.front();
                q.pop();
                pq.push({m[p.second], p.second});
            }
            if (!pq.empty())
            {
                pair<int, char> p = pq.top();
                pq.pop();
                q.push({ans + n + 1, p.second});
                m[p.second]--;
                if (m[p.second] == 0)
                {
                    task--;
                }
            }

            ans++;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << s.leastInterval(tasks, 2) << endl;
}