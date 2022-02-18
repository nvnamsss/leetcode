/*
A substring is a contiguous (non-empty) sequence of characters within a string.

A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.

Given a string word, return the number of vowel substrings in word.

 

Example 1:

Input: word = "aeiouu"
Output: 2
Explanation: The vowel substrings of word are as follows (underlined):
- "aeiouu"
- "aeiouu"
Example 2:

Input: word = "unicornarihan"
Output: 0
Explanation: Not all 5 vowels are present, so there are no vowel substrings.
Example 3:

Input: word = "cuaieuouac"
Output: 7
Explanation: The vowel substrings of word are as follows (underlined):
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
Example 4:

Input: word = "bbaeixoubb"
Output: 0
Explanation: The only substrings that contain all five vowels also contain consonants, so there are no vowel substrings.
 

Constraints:

1 <= word.length <= 100
word consists of lowercase English letters only.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countVowelSubstrings(string word)
    {
        int ans = 0;
        int vow = 0;
        int k = 0;
        int j = 0;
        unordered_map<char, int> m = {
            {'a', 0},
            {'e', 0},
            {'i', 0},
            {'o', 0},
            {'u', 0},
        };

        for (int i = 0; i < word.size(); i++)
        {
            if (m.count(word[i]))
            {
                vow += ++m[word[i]] == 1 ? 1 : 0;
                for (; vow == 5; k++)
                {
                    vow -= --m[word[k]] == 0 ? 1 : 0;
                }
                ans += k - j;
            }
            else
            {
                for (auto &&i : m)
                {
                    i.second = 0;
                }
                vow = 0;
                j = k = i + 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    int rs = s.countVowelSubstrings("cuaieuouac");
    cout << rs << endl;
    rs = s.countVowelSubstrings("aeiouu");
    cout << rs << endl;
}