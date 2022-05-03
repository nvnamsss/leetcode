/*
Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

 

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.
 

Constraints:

1 <= s.length <= 5 * 104
0 <= k <= 50
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> m;
        int ans = 0;
        int count = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
            if (m[s[i]] == 1) {
                count++;
            }

            while (count > k) {
                m[s[left]]--;
                if (m[s[left]] == 0) {
                    count--;
                }
                left++;
            }
        
            ans = max(ans, i - left + 1);
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstringKDistinct("eceba", 2) << endl; 
}