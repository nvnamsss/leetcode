#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
        {
            if (map.find(s[i]) == map.end()) {
                map.insert({s[i], 0});
            }
            map[s[i]]++;
        }
        int even = 0;
        int odd = 0;
        for (auto &&v: map) {
            if (v.second % 2 == 0) {
                even = even + v.second;
            } else {
                odd += odd % 2 == 0 ? v.second : v.second - 1;
            }
        }        
        return even + odd;
    }
};