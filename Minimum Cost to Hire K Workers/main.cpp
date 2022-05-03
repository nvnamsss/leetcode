/*
There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.



Example 1:

Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.


Constraints:

n == quality.length == wage.length
1 <= k <= n <= 104
1 <= quality[i], wage[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        double ans = INT32_MAX;
        vector<vector<double>> ratios = vector<vector<double>>(quality.size(), vector<double>(2));
        for (int i = 0; i < quality.size(); i++)
        {
            ratios[i][0] = (double)wage[i] / (double)quality[i];
            ratios[i][1] = quality[i];
        }

        sort(ratios.begin(), ratios.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        for (int i = 0; i < ratios.size(); i++)
        {
            sum += ratios[i][1];
            pq.push(-ratios[i][1]);
            if (pq.size() > k) {
                sum += pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = min(ans, sum * ratios[i][0]);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    cout << s.mincostToHireWorkers(quality, wage, 2) << endl;

    quality = {3, 1, 10, 10, 1};
    wage = {4, 8, 2, 2, 7};
    cout << s.mincostToHireWorkers(quality, wage, 3) << endl;

    quality = {25,68,35,62,52,57,35,83,40,51};
    wage = {147,97,251,129,438,443,120,366,362,343};
    cout << s.mincostToHireWorkers(quality, wage, 6) << endl;

}