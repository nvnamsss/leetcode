/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.size() == k) return "0";
        deque<char> s;
        for (int i = 0; i < num.size(); i++)
        {
            while (!s.empty() && k > 0 && num[i] < s.back())
            {
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
        }

        while (k > 0 && !s.empty()) {
            s.pop_back();
            k--;
        }

        string ans = "";

        while (!s.empty() && s.front() == '0') {
            s.pop_front();
        }

        while (!s.empty())
        {
            ans = s.back() + ans;
            s.pop_back();
        }

        return ans != "" ? ans : "0";
    }
};

int main()
{
    Solution s;
    cout << s.removeKdigits("1432219", 3) << endl;
    cout << s.removeKdigits("10200", 1) << endl;
    cout << s.removeKdigits("10", 2) << endl;
    cout << s.removeKdigits("10", 1) << endl;
    cout << s.removeKdigits("9", 1) << endl;
    cout << s.removeKdigits("112", 1) << endl;
}