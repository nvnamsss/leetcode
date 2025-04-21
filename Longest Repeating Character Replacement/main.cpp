/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achive this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
        int slidingWindow(string s, int k, char target)
    {
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < s.size())
        {

            if (s[right] != target)
            {
                if (k == 0)
                {
                    while (s[left] == target)
                    {
                        left++;
                    }
                    left++;
                    k++;
                }
                k--;
            }
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for (int i = 'A'; i <= 'Z'; i++)
        {
            ans = max(ans, slidingWindow(s, k, i));
        }
        return ans;
    }
};