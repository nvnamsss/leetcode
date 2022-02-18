/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", s = "dog dog dog dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lower-case English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.

*/

#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> m;
        set<char> set;

        istringstream ss(s);
        vector<string> splitted;
        string split;
        while (ss >> split) {
            splitted.push_back(split);
        }
        if (pattern.size() != splitted.size()) {
            return false;
        }

        for (int i = 0; i < splitted.size(); i++)
        {
            if (m.find(splitted[i]) == m.end() && set.find(pattern[i]) == set.end()) {
                m.insert({splitted[i], pattern[i]});
                set.insert(pattern[i]);
            }
        }

        for (int i = 0; i < pattern.size(); i++)
        {
            if (m[splitted[i]] != pattern[i]) {
                return false;
            }
        }
        
        return true;
    }
};
