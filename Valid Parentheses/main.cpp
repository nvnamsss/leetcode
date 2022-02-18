#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int roundBracket = 0;
        int curlyBracket = 0;
        int squareBracket = 0;
        vector<char> open = vector<char>{'(', '{', '['};
        vector<char> end = vector<char>{')', '}', ']'};
        stack<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (find(open.begin(), open.end(), s[i]) != open.end()) {
                stack.push(s[i]);
            } else {
                if (stack.empty()){
                    return false;
                }
                auto openIndex = find(open.begin(), open.end(), stack.top());
                auto endIndex = find(end.begin(), end.end(), s[i]);

                if (openIndex - open.begin() != endIndex - end.begin()) {
                    return false;
                }

                stack.pop();
            }

        }
        
        return stack.empty();
    }
};