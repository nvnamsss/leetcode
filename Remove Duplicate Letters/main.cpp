#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        stack<char> st;
        string ans = "";
        vector<bool> appeared = vector<bool>(26);
        vector<int> last = vector<int>(26);
        for (int i = 0; i < s.size(); i++)
        {
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            if (appeared[index]) continue;
            while (!st.empty() && st.top() > s[i] && i < last[st.top() - 'a'])
            {
                appeared[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            appeared[index] = true;
        }

        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.removeDuplicateLetters("bcabccc") << endl;
}