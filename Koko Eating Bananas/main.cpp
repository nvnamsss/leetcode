/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int check(vector<int> &piles, int k)
    {
        int ans = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            double v = (double)piles[i] / (double)k;
            ans += ceil(v);
        }
        return ans;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // if (piles.size() == 1) {
        //     double p = piles[0];
        //     double fh = h;
        //     double v = ceil(p / fh);
        //     return v;
        // }

        int minK = 1;
        int maxK = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            maxK = max(maxK, piles[i]);
        }

        int left = minK;
        int right = maxK;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int require = check(piles, mid);
            if (require <= h)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main()
{
    Solution s;
    vector<int> piles = {3, 6, 7, 11};
    cout << s.minEatingSpeed(piles, 8) << endl;
    piles = {30, 11, 23, 4, 20};
    cout << s.minEatingSpeed(piles, 5) << endl;
    piles = {1000000000};
    cout << 100000.0f / 3.0f << endl;
    cout << s.minEatingSpeed(piles, 2) << endl;
    
}