#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int popIndex = 0;
        for (int i = 0; i < pushed.size(); i++)
        {
            while (!s.empty() && popped[popIndex] == s.top())
            {
                s.pop();
                popIndex++;
            }
            s.push(pushed[i]);
            while (!s.empty() && popped[popIndex] == s.top())
            {
                s.pop();
                popIndex++;
            }
        }

        return s.empty();
    }
};

int main()
{
    Solution s;
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    cout << s.validateStackSequences(pushed, popped) << endl;
}