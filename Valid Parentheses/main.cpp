#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> open = {{'(', 0}, {'{', 1}, {'[', 2}};
        unordered_map<char, int> close = {{')', 0}, {'}', 1}, {']', 2}};
        stack<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (open.find(s[i]) != open.end()) {
                stack.push(s[i]);
            } else {
                if (stack.empty()) {
                    return false;
                }

                int o = open[stack.top()];
                int e = close[s[i]];
                if (o != e) {
                    return false;
                }
                stack.pop();
            }

        }
        
        return stack.empty();
    }
};