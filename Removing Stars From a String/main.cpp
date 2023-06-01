#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string useStack(string s)
    {
        vector<bool> removed = vector<bool>(s.size());
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                removed[i] = true;
                if (st.empty())
                {
                    continue;
                }

                int top = st.top();
                st.pop();

                if (top >= 0)
                {
                    removed[top] = true;
                    top--;
                    if (top >= 0 && s[top] != '*')
                    {
                        st.push(top);
                    }
                }
            }
            else
            {

                if (i < s.size() - 1 && s[i + 1] == '*')
                {
                    st.push(i);
                }
            }
        }

        int p = 0;
        int l = 0;
        for (int i = 0; i < removed.size(); i++)
        {
            if (!removed[i])
            {
                l++;
            }
        }
        string ans;
        ans.reserve(l);
        for (int i = 0; i < s.size(); i++)
        {
            if (!removed[i])
            {
                ans.push_back(s[i]);
                p++;
            }
            /* code */
        }

        return ans;
    }

public:
    string removeStars(string s)
    {
        return useStack(s);
    }
};

int main()
{
    Solution s;
    cout << s.removeStars("leet**cod*e") << endl;
    cout << s.removeStars("leet******") << endl;


}