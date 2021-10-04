#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int min = prices[0];
        int profit = prices[1] - min;        
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < min) {
                min = prices[i];
            } else {
                profit = max(profit, prices[i] - min);
            }
        }
        
        return max(profit, 0);
    }
};