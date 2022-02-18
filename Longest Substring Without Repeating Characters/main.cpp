#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int milestone = 0;
        unordered_map<char, int> map;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (map.find(s[i]) == map.end()) {
                map.insert({s[i], i + 1});
            } else {
                milestone = max(map[s[i]], milestone);
                map[s[i]] = i + 1;
            }

            ans = max(ans, i - milestone + 1);
        }

        return ans;        
    }
};

int main() {
    Solution s;

}