/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs[0].size();
        for (int i = 0; i < strs.size(); i++)
        {
            int ssize = strs[i].size();
            length = min(length, ssize);
        }
        
        bool same = true;
        int index = 0;
        while (index < length && same) {
            char c = strs[0][index];
            for (int i = 1; i < strs.size(); i++) {
                same = same && c == strs[i][index]; 
            }
            if (same)
                index++;
        }

        return strs[0].substr(0, index);
    }
};

int main() {
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(strs) << endl;
    strs = {"dog", "racecar", "car"};
    cout << s.longestCommonPrefix(strs) << endl;
    strs = {"dog", "doracecar", "docar"};
    cout << s.longestCommonPrefix(strs) << endl;
    strs = {"dog", "doracecar", ""};
    cout << s.longestCommonPrefix(strs) << endl;
    strs = {"d"};
    cout << s.longestCommonPrefix(strs) << endl;
}