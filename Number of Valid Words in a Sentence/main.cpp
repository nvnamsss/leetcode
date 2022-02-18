/*

User Accepted:3698
User Tried:4692
Total Accepted:3810
Total Submissions:16337
Difficulty:Easy
A sentence consists of lowercase letters ('a' to 'z'), digits ('0' to '9'), hyphens ('-'), punctuation marks ('!', '.', and ','), and spaces (' ') only. Each sentence can be broken down into one or more tokens separated by one or more spaces ' '.

A token is a valid word if all three of the following are true:

It only contains lowercase letters, hyphens, and/or punctuation (no digits).
There is at most one hyphen '-'. If present, it must be surrounded by lowercase characters ("a-b" is valid, but "-ab" and "ab-" are not valid).
There is at most one punctuation mark. If present, it must be at the end of the token ("ab,", "cd!", and "." are valid, but "a!b" and "c.," are not valid).
Examples of valid words include "a-b.", "afad", "ba-c", "a!", and "!".

Given a string sentence, return the number of valid words in sentence.

 

Example 1:

Input: sentence = "cat and  dog"
Output: 3
Explanation: The valid words in the sentence are "cat", "and", and "dog".
Example 2:

Input: sentence = "!this  1-s b8d!"
Output: 0
Explanation: There are no valid words in the sentence.
"!this" is invalid because it starts with a punctuation mark.
"1-s" and "b8d" are invalid because they contain digits.
Example 3:

Input: sentence = "alice and  bob are playing stone-game10"
Output: 5
Explanation: The valid words in the sentence are "alice", "and", "bob", "are", and "playing".
"stone-game10" is invalid because it contains digits.
Example 4:

Input: sentence = "he bought 2 pencils, 3 erasers, and 1  pencil-sharpener."
Output: 6
Explanation: The valid words in the sentence are "he", "bought", "pencils,", "erasers,", "and", and "pencil-sharpener.".
 

Constraints:

1 <= sentence.length <= 1000
sentence only contains lowercase English letters, digits, ' ', '-', '!', '.', and ','.
There will be at least 1 token.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countValidWords(string sentence)
    {
        int ans = 0;
        int valid = 1;
        int hyphen = 0;
        sentence += ' ';
        for (int i = 0; i < sentence.size(); i++)
        {
            if (i > 0 && sentence[i - 1] != ' ' && sentence[i] == ' ')
            {
                ans += valid;
                valid = 1;
                hyphen = 0;
            }

            if (sentence[i] == '-')
            {
                hyphen++;
                if (hyphen > 1 || i == 0 || i == sentence.size() - 1 ||
                 sentence[i + 1] < 'a' || sentence[i + 1] > 'z' || sentence[i-1] < 'a' || sentence[i - 1] > 'z')
                {
                    valid = 0;
                }
            }

            if (sentence[i] == '!' || sentence[i] == '.' || sentence[i] == ',')
            {
                if (i + 1 < sentence.size() && sentence[i + 1] != ' ')
                {
                    valid = 0;
                }
            }
            if (sentence[i] >= '0' && sentence[i] <= '9')
            {
                valid = 0;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int rs = s.countValidWords("cat and  dog");
    cout << rs << endl;
    rs = s.countValidWords("alice and  bob are playing stone-game10");
    cout << rs << endl;
    rs = s.countValidWords("he bought 2 pencils, 3 erasers, and 1  pencil-sharpener.");
    cout << rs << endl;
    rs = s.countValidWords("!this  1-s b8d!");
    cout << rs << endl;
    rs = s.countValidWords("f    6c x2");
    cout << rs << endl;
    rs = s.countValidWords("!g 3 !sy ");
    cout << rs << endl;
    rs = s.countValidWords(". ! 7hk  al6 l! aon49esj35la k3 7u2tkh  7i9y5  !jyylhppd et v- h!ogsouv 5");
    cout << rs << endl;

}