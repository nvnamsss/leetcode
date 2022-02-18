#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> result;
    void backtrack(string s, int open, int close, int limit)
    {
        if (s.size() == limit * 2)
        {
            result.push_back(s);
            return;
        }

        if (open < limit)
        {
            // s.append("(");
            backtrack(s + "(", open + 1, close, limit);
        }

        if (close < open)
        {
            // s.append(")");
            backtrack(s + ")", open, close + 1, limit);
        }
    }

    vector<string> generateParenthesis(int n) {
        result = vector<string>();
        string s = string();
        backtrack(s, 0, 0, n);
        return result;
    }
};

int main()
{
    Solution s = Solution();
    cin.get();
}