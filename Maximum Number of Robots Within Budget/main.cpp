/*
You have n robots. You are given two 0-indexed integer arrays, chargeTimes and runningCosts, both of length n. The ith robot costs chargeTimes[i] units to charge and costs runningCosts[i] units to run. You are also given an integer budget.

The total cost of running k chosen robots is equal to max(chargeTimes) + k * sum(runningCosts), where max(chargeTimes) is the largest charge cost among the k robots and sum(runningCosts) is the sum of running costs among the k robots.

Return the maximum number of consecutive robots you can run such that the total cost does not exceed budget.

 

Example 1:

Input: chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
Output: 3
Explanation: 
It is possible to run all individual and consecutive pairs of robots within budget.
To obtain answer 3, consider the first 3 robots. The total cost will be max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24 which is less than 25.
It can be shown that it is not possible to run more than 3 consecutive robots within budget, so we return 3.
Example 2:

Input: chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
Output: 0
Explanation: No robot can be run that does not exceed the budget, so we return 0.
 

Constraints:

chargeTimes.length == runningCosts.length == n
1 <= n <= 5 * 104
1 <= chargeTimes[i], runningCosts[i] <= 105
1 <= budget <= 1015
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int simulate(vector<int>& chargeTimes, vector<int>& runningCosts, int numRobot) {
        // ll ans = 0;
        int ans = 0;
        long sum = 0;
        int n = chargeTimes.size();
        deque<pair<int, int>> dq;

        // for (int i = 0; i < n; ++i) {
        //     sum += runningCosts[i];

        //     if (i >= numRobot) {
        //         sum -= runningCosts[i - numRobot];
        //     }

        //     while (!dq.empty() && dq.back().first < chargeTimes[i]) {
        //         dq.pop_back();
        //     }

        //     if (!dq.empty() && dq.front().second <= i - numRobot) {
        //         dq.pop_front();
        //     }

        //     dq.push_back({chargeTimes[i], i});
        //     long chargeCost = dq.front().first;
        //     long long cost = chargeCost + numRobot * sum;
        //     ans = max(ans, cost);
        // }

        return ans;
    }
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int l = 0;
        // int r = chargeTimes.size();
        // while (l <= r) {
        //     int m = l + (r - l) / 2;
        //     long long cost = simulate(chargeTimes, runningCosts, m);
        //     if (cost > budget) {
        //         r = m - 1;
        //     } else {
        //         l = m + 1;
        //     }
        // }

        return l;
    }
};

int main() {
    Solution s;
    vector<int> charge = {1};
    vector<int> run = {1};
    s.maximumRobots(charge, run, 1);
}