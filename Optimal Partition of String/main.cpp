#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        int i = 0;

        while (i < s.size()){
            unordered_set<char> set;
            while (i < s.size() && !set.count(s[i])) {
                set.insert(s[i]);
                i++;
            }
            
            ans++;
        }
        return ans;
    }
};  