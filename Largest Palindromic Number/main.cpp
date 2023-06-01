/*
You are given a string num consisting of digits only.

Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.

Notes:

You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.


Example 1:

Input: num = "444947137"
Output: "7449447"
Explanation:
Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed.
Example 2:

Input: num = "00009"
Output: "9"
Explanation:
It can be shown that "9" is the largest palindromic integer that can be formed.
Note that the integer returned should not contain leading zeroes.


Constraints:

1 <= num.length <= 105
num consists of digits.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestPalindromic(string num)
    {
        vector<int> freqs = vector<int>(10);
        for (int i = 0; i < num.size(); i++)
        {
            int at = num[i] - '0';
            freqs[num[i] - '0']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < freqs.size(); i++)
        {
            while (freqs[i] > 1)
            {
                pq.push(i);
                freqs[i] -= 2;
            }
        }

        string first = "";
        int last = -1;
        if (!pq.empty() && pq.top() != 0)
        {
            while (!pq.empty())
            {
                int v = pq.top();
                pq.pop();
                first += v + '0';
            }
        } else {
            if (!pq.empty()) {
                last = 0;
            }
        }
        
        for (int i = 0; i < freqs.size(); i++)
        {
            if (freqs[i] > 0)
            {
                last = max(last, i);
            }
        }

        string second = first;
        reverse(second.begin(), second.end());
        char m = last + '0';
        return last == -1 ? first + second : first + m + second;
    }
};

int main() {
    Solution s;
    cout << s.largestPalindromic("444947137") << endl;
    cout << s.largestPalindromic("00009") << endl;
    cout << s.largestPalindromic("00000000") << endl;
}