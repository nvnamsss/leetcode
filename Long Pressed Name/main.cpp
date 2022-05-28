/*
Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.



Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it was not in the typed output.


Constraints:

1 <= name.length, typed.length <= 1000
name and typed consist of only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int l2 = 0;
        for (int i = 0; i < name.size(); i++)
        {
            if (name[i] != typed[l2])
            {
                return false;
            }
            l2++;
            if (name[i] != name[i + 1]) {
                while (typed[l2] == name[i])
                {
                    l2++;
                }
            }

        }

        return l2 == typed.size();
    }
};

int main()
{
    Solution s;
    cout << s.isLongPressedName("alex", "aaleex") << endl;
    cout << s.isLongPressedName("leelee", "lleeelee") << endl;
    cout << s.isLongPressedName("alex", "aaleexa") << endl;
}