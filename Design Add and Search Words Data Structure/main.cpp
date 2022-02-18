/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search.

*/

#include <bits/stdc++.h>
using namespace std;

class WordDictionary
{
    unordered_map<char, WordDictionary *> words;
    bool end;
    bool search(string word, int i)
    {
        if (i == word.size())
        {
            return end;
        }

        if (word[i] == '.')
        {

            for (auto &&v : words)
            {
                if (v.second->search(word, i + 1))
                    return true;
            }
        }
        else
        {
            if (words.find(word[i]) != words.end())
            {
                return words[word[i]]->search(word, i + 1);
            }
        }

        return false;
    }

public:
    WordDictionary()
    {
        end = false;
    }

    void addWord(string word)
    {
        WordDictionary *w = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (w->words.find(word[i]) == w->words.end())
            {
                WordDictionary *n = new WordDictionary();
                w->words.insert({word[i], n});
            }
            w = w->words[word[i]];
        }
        w->end = true;
    }

    bool search(string word)
    {
        return search(word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main()
{
    WordDictionary w;
    w.addWord("bad");

    bool rs = w.search("bad");
    cout << "rs: " << rs << endl;
}