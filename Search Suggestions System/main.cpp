/*
You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Example 3:

Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
 

Constraints:

1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;



class Trie {
    vector<Trie*> tries;
    bool end;


    void strings(vector<string>& v, string& s) {
        if (v.size() == 3) {
            return;
        }

        if (end) {
            v.push_back(s);
        }

        for (int i = 0; i < tries.size(); i++)
        {
            if (tries[i]) {
                char c = 'a' + i;
                s += c;
                tries[i]->strings(v, s);
                s.pop_back();
            }
        }
    }
public:
    Trie() {
        tries = vector<Trie*>(26, NULL);
        end = false;
    }

    bool contains(char c) {
        return tries[c - 'a'];
    }

    Trie* get(char c) {
        return tries[c - 'a'];
    }

    void add(string word) {
        Trie* t = this;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (!t->tries[index]) {
                t->tries[index] = new Trie();
            }
            t = t->tries[index];
        }
        t->end = true;
        
    }

    vector<string> strings(string prefix) {
        vector<string> result;
        strings(result, prefix);
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        for (int i = 0; i < products.size(); i++)
        {
            trie->add(products[i]);
        }

        vector<vector<string>> ans = vector<vector<string>>(searchWord.size());
        string prefix = "";
        Trie* t = trie;

        for (int i = 0; i < searchWord.size(); i++)
        {
            t = t->get(searchWord[i]);
            if (!t) {
                break;
            }
            prefix += searchWord[i];
            vector<string> subans = t->strings(prefix);
            ans[i] = subans;
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    s.suggestedProducts(products, "mouse");
}