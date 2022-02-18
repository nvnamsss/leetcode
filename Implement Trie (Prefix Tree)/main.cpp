/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/

#include <bits/stdc++.h>
using namespace std;

class Trie
{
    unordered_map<char, Trie *> tries;
    bool end;
public:
    Trie()
    {
        end = false;
    }

    void insert(string word)
    {
        Trie *t = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (t->tries.find(word[i]) == t->tries.end())
            {
                Trie *n = new Trie();
                t->tries.insert({word[i], n});
            }

            t = t->tries[word[i]];
        }
        t->end = true;
    }

    bool search(string word)
    {
        Trie *t = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (t->tries.find(word[i]) == t->tries.end())
            {
                return false;
            }
            t = t->tries[word[i]];
        }

        return t->end;
    }

    bool startsWith(string prefix)
    {
        Trie *t = this;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (t->tries.find(prefix[i]) == t->tries.end())
            {
                return false;
            }
            t = t->tries[prefix[i]];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */