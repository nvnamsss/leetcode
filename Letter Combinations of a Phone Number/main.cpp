/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<string> result;
    unordered_map<char, vector<char>> map = unordered_map<char, vector<char>>{
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}};

    void recursive(string digits, string set, int index)
    {
        if (index == digits.size())
        {
            result.push_back(set);
            return;
        }

        vector<char> items = map[digits[index]];
        for (int i = 0; i < items.size(); i++)
        {
            recursive(digits, set + items[i], index + 1);
        }
        
    }

public:
    vector<string> letterCombinations(string digits)
    {
        // if (digits == "") {
        //     return vector<string>{""};
        // }
        recursive(digits, "", 0);
        return result;
    }
};