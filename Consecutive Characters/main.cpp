#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int consecutive = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1]) {
                consecutive++;
            } else {
                consecutive = 1;
            }
            ans = max(ans, consecutive);
        }
        
        return ans;
    }
};