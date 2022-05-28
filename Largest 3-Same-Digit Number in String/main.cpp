/*
You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.
 

Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.
Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
 

Constraints:

3 <= num.length <= 1000
num only consists of digits.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char current_char = num[0];
        vector<bool> appearance = vector<bool>(10);
        int count = 1;
        for (int i = 1; i < num.size(); i++)
        {
            if (num[i] != current_char) {
                current_char = num[i];
                count = 0;
            }
            count++;
            if (count == 3) {
                appearance[num[i] - '0'] = true;
            }
        }
        
        int v = -1;
        for (int i = 0; i <= 9; i++)
        {
            if (appearance[i]) {
                v = i;
            }
        }
        
        if (v == -1) return "";
        string ans = string(3, v + '0');
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.largestGoodInteger("6777133339") << endl;
    cout << s.largestGoodInteger("2300019") << endl;
    cout << s.largestGoodInteger("42352338") << endl;
}