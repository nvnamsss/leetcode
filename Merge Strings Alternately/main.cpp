/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        ans.reserve(word1.size() + word2.size());
        int p = 0;
        int p1 = 0;
        int p2 = 0;
        while (p1 < word1.size() && p2 < word2.size()) {
            ans.push_back(word1[p1++]);
            ans.push_back(word2[p2++]);
        }

        while (p1 < word1.size()) {
            ans.push_back(word1[p1++]);
        }
        while (p2 < word2.size()) {
            ans.push_back(word2[p2++]);
        }

        return ans;
    }
};

int main() {
    Solution s;
    string w1 = "abc";
    string w2 = "pqr";
    s.mergeAlternately(w1, w2);
}