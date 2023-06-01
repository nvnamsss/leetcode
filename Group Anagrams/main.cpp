/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
    string freq2str(vector<int> freqs) {
        string ans = "";
        for (int i = 0; i < freqs.size(); i++) {
            if (freqs[i] > 0) {
                char c = i + 'a';
                ans += c + to_string(freqs[i]);
            }
        }
        return ans;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> freqs = vector<int>(26);
            for (int j = 0; j < strs[i].size(); j++) {
                freqs[strs[i][j] - 'a']++;
            }

            string encoded = freq2str(freqs);
            m[encoded].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto &&i : m) {
            ans.push_back(i.second);
        }
        return ans;
    }
};