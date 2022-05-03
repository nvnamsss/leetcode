#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solution(vector<int>& prices, vector<int>& discount) {
        int ans = 0;
        sort(discount.begin(), discount.end());
        sort(prices.begin(), prices.end());
        int pLength = prices.size() - 1;
        int dLength = discount.size() - 1;
        while (pLength >= 0 && dLength >= 0) {
            ans += prices[pLength] * (100 - discount[dLength]) / 100;
            pLength--;
            dLength--;
        }

        while (pLength >= 0) {
            ans += prices[pLength];
            pLength--;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> prices = {13000, 88000, 10000};
    vector<int> discount = {30, 20};

    cout << s.solution(prices, discount) << endl;

    prices = {32000, 18000, 42500};
    discount = {50, 20, 65};
    cout << s.solution(prices, discount) << endl;
        prices = {32000, 18000, 42500};
    discount = {50, 20, 65, 10, 5};
    cout << s.solution(prices, discount) << endl;
}