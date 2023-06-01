/*
You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:

Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
The cost of the swap is min(basket1[i],basket2[j]).
Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

Return the minimum cost to make both the baskets equal or -1 if impossible.

 

Example 1:

Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
Output: 1
Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
Example 2:

Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
Output: -1
Explanation: It can be shown that it is impossible to make both the baskets equal.
 

Constraints:

basket1.length == bakste2.length
1 <= basket1.length <= 105
1 <= basket1[i],basket2[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> m;
        vector<int> swaps;
        long long ans = 0;
        int smallest = INT32_MAX;
        for (int i = 0; i < basket1.size(); i++)
        {
            m[basket1[i]]++;
            smallest = min(smallest, basket1[i]);
        }
        
        for (int i = 0; i < basket2.size(); i++)
        {
            m[basket2[i]]--;
            smallest = min(smallest, basket2[i]);
        }
        
        for (auto &&it: m) {
            if (it.second % 2) {
                return -1;
            }
            
            int v = abs(it.second);
            for (int i = 0; i < v / 2; i++)
            {
               swaps.push_back(it.first); 
            }
            
        }

        nth_element(swaps.begin(), swaps.begin() + swaps.size() / 2, swaps.end());
        for (int i = 0; i < swaps.size() / 2; i++)
        {
            ans += min(swaps[i], smallest * 2);
        }
        

        return ans;
    }
};