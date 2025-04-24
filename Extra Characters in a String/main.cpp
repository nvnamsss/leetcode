/*
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.


Example 1:

Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:

Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.

Constraints:

1 <= s.length <= 50
1 <= dictionary.length <= 50
1 <= dictionary[i].length <= 50
dictionary[i] and s consists of only lowercase English letters
dictionary contains distinct words
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
    }
};

class Trie
{
    vector<Trie *> tries;
    bool end;

public:
    Trie()
    {
        tries = vector<Trie *>(26);
        end = false;
    }

    void add(string s)
    {
        Trie *cur = this;
        for (int i = 0; i < s.size(); ++i)
        {
            int c = s[i] - 'a';
            if (!cur->tries[c])
            {
                cur->tries[c] = new Trie();
            }
            cur = cur->tries[c];
        }
        cur->end = true;
    }

    bool find(string s)
    {
        Trie *cur = this;
        for (int i = 0; i < s.size() && cur; ++i)
        {
            int c = s[i] - 'a';
            cur = cur->tries[c];
        }

        return cur && cur->end;
    }

    vector<string> findStrings(string s, int p)
    {
        vector<string> ans = {};
        Trie *cur = this;
        string w = "";
        while (cur)
        {
            if (cur->end) {
                ans.push_back(w);
            }
            int c = s[p] - 'a';
            cur = cur->tries[c];
            w += s[p];
            ++p;
        }
        return ans;
    }

    Trie *get(char c)
    {
        int i = c - 'a';
        return tries[i];
    }
};

class Solution
{
    int usingDp(string s, vector<string> dictionary)
    {
        int n = s.length();
        unordered_set<string> dictionarySet(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1, 0);

        for (int start = n - 1; start >= 0; start--)
        {
            dp[start] = dp[start + 1] + 1;
            for (int end = start; end < n; end++)
            {
                auto curr = s.substr(start, end - start + 1);
                if (dictionarySet.count(curr))
                {
                    dp[start] = min(dp[start], dp[end + 1]);
                }
            }
        }

        return dp[0];
    }

    int recursive(string s, vector<int>& memo, Trie *t, int p)
    {
        if (memo[p] != -1) {
            return memo[p];
        }
        int ans = 0;
        vector<string> possibilities = t->findStrings(s, p);
        if (possibilities.size() == 0) {
            ans = ans + recursive(s, memo, t, p + 1) + 1;
        } else {
            int subans = INT32_MAX;
            for (int i = 0; i < possibilities.size(); ++i) {
                subans = min(subans, recursive(s, memo, t, p + possibilities[i].size()));
            }
            ans = ans + subans;
        }
        
        memo[p] = ans;
        return ans;
    }

    int usingTrie(string s, vector<string> dictionary)
    {
        Trie *t = new Trie();
        vector<int> memo = vector<int>(s.size(), -1);
        for (int i = 0; i < dictionary.size(); ++i)
        {
            t->add(dictionary[i]);
        }

        return recursive(s, memo, t, 0);
    }

public:
    int minExtraChar(string s, vector<string> dictionary)
    {
        return usingTrie(s, dictionary);
    }
};

int main()
{
    Solution s;
    vector<string> dic = {"leet", "code", "leetcode"};
    cout << s.minExtraChar("leetscode", dic) << endl;

    dic = {"hello","world"};
    cout << s.minExtraChar("sayhelloworld", dic) << endl;

    return 0;
}
