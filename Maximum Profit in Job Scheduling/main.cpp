/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:



Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
Example 3:



Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
 

Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 104
1 <= startTime[i] < endTime[i] <= 109
1 <= profit[i] <= 104
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<int> dp;

    struct job
    {

        int startTime;
        int endTime;
        int profit;
        job(int startTime, int endTime, int profit) : startTime(startTime), endTime(endTime), profit(profit)
        {
        }
    };

    static bool compareJobByStartTime(job *j1, job *j2)
    {
        return j1->startTime < j2->startTime;
    }

    int binarySearch(vector<job *> &jobs, int target)
    {
        int l = 0;
        int r = jobs.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (jobs[mid]->startTime == target)
                return mid;
            else if (jobs[mid]->startTime > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l + 1;
    }

    int recursive(vector<job *> &jobs, int i)
    {
        if (i >= jobs.size())
            return 0;
        if (dp[i] != 0)
            return dp[i];

        int l = i;
        while (l < jobs.size() && jobs[l]->startTime < jobs[i]->endTime) {
            l++;
        }
        // int l = binarySearch(jobs, jobs[i]->endTime);

        int maxProfit = recursive(jobs, i + 1);
        maxProfit = max(maxProfit, recursive(jobs, l) + jobs[i]->profit);

        dp[i] = maxProfit;
        return maxProfit;
    }

public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<job *> jobs = vector<job *>();
        dp = vector<int>(n, 0);

        for (int i = 0; i < n; i++)
        {
            job *j = new job(startTime[i], endTime[i], profit[i]);
            jobs.push_back(j);
        }

        sort(jobs.begin(), jobs.end(), compareJobByStartTime);

        return recursive(jobs, 0);
    }
};

int main()
{
    Solution s;
    vector<int> start = vector<int>{1, 2, 3, 3};
    vector<int> end = vector<int>{3, 4, 5, 6};
    vector<int> profit = vector<int>{50, 10, 40, 70};

    int rs = s.jobScheduling(start, end, profit);
    cout << "max profit: " << rs << endl;

    start = vector<int>{1, 2, 3, 4, 6};
    end = vector<int>{3, 5, 10, 6, 9};
    profit = vector<int>{20, 20, 100, 70, 60};
    rs = s.jobScheduling(start, end, profit);
    cout << "max profit: " << rs << endl;

    start = vector<int>{1, 1, 1};
    end = vector<int>{2, 3, 4};
    profit = vector<int>{5, 6, 4};
    rs = s.jobScheduling(start, end, profit);
    cout << "max profit: " << rs << endl;
}