/*
Design a special dictionary with some words that searchs the words in it by a prefix and a suffix.

Implement the WordFilter class:

WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string prefix, string suffix) Returns the index of the word in the dictionary, which has the prefix prefix and the suffix suffix. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
 

Example 1:

Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]

Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".
 

Constraints:

1 <= words.length <= 15000
1 <= words[i].length <= 10
1 <= prefix.length, suffix.length <= 10
words[i], prefix and suffix consist of lower-case English letters only.
At most 15000 calls will be made to the function f.

*/

#include <bits/stdc++.h>
using namespace std;

class Trie {
    unordered_map<char, Trie*> tries;
    int index;
public:
    Trie() {
        index = -1;
    }

    int find(string s) {
        Trie* trie = this;
        for (int i = 0; i < s.size(); i++)
        {
            if (trie->tries.find(s[i]) == trie->tries.end()) {
                return -1;
            }
            trie = trie->tries[s[i]];
        }
        return trie->index;
    }

    Trie* add(string s, int index) {
        Trie* trie = this;

        for (int i = 0; i < s.size(); i++)
        {
            if (trie->tries.find(s[i]) == trie->tries.end()) {
                Trie* nt = new Trie();
                trie->tries[s[i]] = nt;
            }
            trie = trie->tries[s[i]];
            trie->index = index;
        }

        trie->index = index;
        return trie;
    }

    
};

class WordFilter {
    Trie* trie;
public:
    WordFilter(vector<string>& words) {
        trie = new Trie();
        for (int i = 0; i < words.size(); i++)
        {
            string s = "#" + words[i];
            trie->add(s, i);    

            for (int j = words[i].size() - 1; j >= 0; j--)
            {
                s = words[i][j] + s;
                trie->add(s, i);
            }
            
        }
    }
    
    int f(string prefix, string suffix) {
        string s = suffix + "#" + prefix;
        return trie->find(s);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

int main() {    
    vector<string> words = {"apple"};
    WordFilter wf = WordFilter(words);
    cout << wf.f("a", "e") << endl;
}