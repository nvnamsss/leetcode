#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        sort(s.begin(), s.end());
        unordered_set<int> existed;
        int i = 0;
        while (i < s.size()) {
            char c = s[i];
            int count = 0;
            i++;
            while (i < s.size() && c == s[i]) {
                count++;
                i++;
            }

            while (existed.count(count)) {
                count--;
                ans++;
            }

            if (count > 0) {
                existed.insert(count);
            }
        }

        return ans;
    }
};