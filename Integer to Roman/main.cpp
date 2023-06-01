/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<int, char>> tenth = {
        {1000, 'M'}, {100, 'C'}, {10, 'X'},{1, 'I'}
    };
    
    unordered_map<int, char> fifth = {
        {100, 'D'},
        {10, 'L'},
        {1, 'V'}
    };
    vector<pair<int, char>> values = {
        {1000, 'M',}, {500, 'D'}, {100, 'C'}, {50, 'L'}, {10, 'X'}, {5, 'V'}, {1, 'I'}
    };
public:
    string intToRoman(int num) {
        int i = 0;
        string ans = "";
        while (num > 0) {
            while (tenth[i].first > num) {
                i++;
            }
            int value = tenth[i].first;
            int character = tenth[i].second;
            int count = num / value;

            if (count == 9) {
                ans += character;
                ans += tenth[i-1].second;
            } else if (count == 4) {
                ans += character;
                ans += fifth[value];
            }  else if (count >= 5) {
                ans += fifth[value];
                for (int i = 5; i < count; i++) {
                    ans += character;
                }
            } else {
                for (int i = 0; i < count; i++) {
                    ans += character;
                }
            }
            num -= count * value;            
        }

        return ans;        
    }
};

int main() {
    Solution s;
    cout << s.intToRoman(1994) << endl;
}