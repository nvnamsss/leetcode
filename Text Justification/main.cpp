/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.


Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]


Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> distributeSpace(int space, int slot) {
        int base = space / slot;
        vector<int> spaces = vector<int>(slot, base);
        int i = 0;
        space -= base * slot;
        while (space > 0) {
            spaces[i] += 1;
            --space;
            i = (i + 1) % slot;
        }
        return spaces;
    }
    // justify in range [l, r)
    string justify(vector<string> &words, int l, int r, int wordSpace, int maxWidth)
    {
        string ans = "";
        int slot = r - l - 1;
        if (r - l == 1)
        {
            ans += words[l];
            while (ans.size() < maxWidth)
            {
                ans += ' ';
            }
        }
        else
        {
            vector<int> spaces = distributeSpace(maxWidth - wordSpace, slot);
            ans += words[l];
            for (int i = l + 1; i < r; ++i)
            {
                int pad = spaces[i - l - 1];
                for (int j = 0; j < pad; ++j)
                {
                    ans += ' ';
                }
                ans += words[i];
                cout << ans.size() << endl;
            }
        }

        return ans;
    }

    string justifyLastWord(vector<string> &words, int l, int maxWidth)
    {
        int r = words.size();
        string ans = "";
        ans += words[l];
        l++;
        while (l < r)
        {
            ans += " " + words[l];
            l++;
        }

        while (ans.size() < maxWidth)
        {
            ans += ' ';
        }

        return ans;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<int> prefix = vector<int>(words.size() + 1);
        for (int i = 0; i < words.size(); ++i)
        {
            prefix[i + 1] = prefix[i] + words[i].size();
        }

        // l: 0 -> n - 1
        // r: 1 -> n
        // justify from l -> r - 1 means [l, r - 1]
        int l = 0;
        int r = 1;
        vector<string> ans;
        while (r <= words.size())
        {
            while (r + 1 <= words.size() && (prefix[r + 1] - prefix[l] + (r - l)) <= maxWidth)
            {
                r++;
            }
            // process here
            string justified = "";
            if (r < words.size()) {
                justified = justify(words, l, r, prefix[r] - prefix[l], maxWidth);
            } else {
                justified = justifyLastWord(words, l, maxWidth);
            }
            ans.push_back(justified);
            l = r;
            r++;
        }

        return ans;
    }
};

void print(vector<string> &ans)
{
    cout << "--------" << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << endl;
    }
    cout << "--------" << endl;
}

int main()
{
    Solution s;
    vector<string> words = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    vector<string> ans = s.fullJustify(words, 16);
    print(ans);
    s.distributeSpace(5, 3);
    // vector<string> sub = {"this", "is", "an"};
    // s.justify(sub, 0, 3, 8, 2, 16);
    // ["ask   not   what","your country can","do  for  you ask","what  you  cando","for your country"]
    // ["ask   not   what","your country can","do  for  you ask","what  you can do","for your country"]
}