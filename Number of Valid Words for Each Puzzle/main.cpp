/*
With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
word contains the first letter of puzzle.
For each letter in word, that letter is in puzzle.
For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage", while
invalid words are "beefed" (does not include 'a') and "based" (includes 's' which is not in the puzzle).
Return an array answer, where answer[i] is the number of words in the given word list words that is valid with respect to the puzzle puzzles[i].
 

Example 1:

Input: words = ["aaaa","asas","able","ability","actt","actor","access"], puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
Output: [1,1,3,2,4,0]
Explanation: 
1 valid word for "aboveyz" : "aaaa" 
1 valid word for "abrodyz" : "aaaa"
3 valid words for "abslute" : "aaaa", "asas", "able"
2 valid words for "absoryz" : "aaaa", "asas"
4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
There are no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.
Example 2:

Input: words = ["apple","pleas","please"], puzzles = ["aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"]
Output: [0,1,3,2,0]
 

Constraints:

1 <= words.length <= 105
4 <= words[i].length <= 50
1 <= puzzles.length <= 104
puzzles[i].length == 7
words[i] and puzzles[i] consist of lowercase English letters.
Each puzzles[i] does not contain repeated characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int c2i(char c)
    {
        return c - 'a';
    }

    int bitmask(string s)
    {
        int v = 0;
        for (int j = 0; j < s.size(); j++)
        {
            v |= (1 << c2i(s[j]));
        }

        return v;
    }

public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        vector<int> rs = vector<int>(puzzles.size(), 0);
        unordered_map<int, int> count;
        for (int i = 0; i < words.size(); i++)
        {
            int v = bitmask(words[i]);
            count[v]++;
        }

        for (int i = 0; i < puzzles.size(); i++)
        {
            int first = 1 << c2i(puzzles[i][0]);
            int c = count[first];
            // int v = bitmask(puzzles[i]);
            int mask = bitmask(puzzles[i].substr(1));

            for (int submask = mask; submask; submask = (submask - 1) & mask)
            {
                c += count[submask | first];
            }

            rs[i] = c;
        }

        return rs;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"aaaa"};
    vector<string> puzzles = {"aboveyz"};
    s.findNumOfValidWords(words, puzzles);
}