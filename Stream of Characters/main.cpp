/*
Design an algorithm that accepts a stream of characters and checks if a suffix of these characters is a string of a given array of strings words.

For example, if words = ["abc", "xyz"] and the stream added the four characters (one by one) 'a', 'x', 'y', and 'z', your algorithm should detect that the suffix "xyz" of the characters "axyz" matches "xyz" from words.

Implement the StreamChecker class:

StreamChecker(String[] words) Initializes the object with the strings array words.
boolean query(char letter) Accepts a new character from the stream and returns true if any non-empty suffix from the stream forms a word that is in words.
 

Example 1:

Input
["StreamChecker", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query"]
[[["cd", "f", "kl"]], ["a"], ["b"], ["c"], ["d"], ["e"], ["f"], ["g"], ["h"], ["i"], ["j"], ["k"], ["l"]]
Output
[null, false, false, false, true, false, true, false, false, false, false, false, true]

Explanation
StreamChecker streamChecker = new StreamChecker(["cd", "f", "kl"]);
streamChecker.query("a"); // return False
streamChecker.query("b"); // return False
streamChecker.query("c"); // return False
streamChecker.query("d"); // return True, because 'cd' is in the wordlist
streamChecker.query("e"); // return False
streamChecker.query("f"); // return True, because 'f' is in the wordlist
streamChecker.query("g"); // return False
streamChecker.query("h"); // return False
streamChecker.query("i"); // return False
streamChecker.query("j"); // return False
streamChecker.query("k"); // return False
streamChecker.query("l"); // return True, because 'kl' is in the wordlist
 

Constraints:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
words[i] consists of lowercase English letters.
letter is a lowercase English letter.
At most 4 * 104 calls will be made to query.
*/

#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    bool word;
    vector<Trie*> vtries;
    unordered_map<char, Trie *> tries;
    Trie()
    {
        vtries = vector<Trie*>(26);
        word = false;
    }
};

class StreamChecker
{
    string streamString = "";
    Trie *trie;
    queue<Trie*> q;
public:
    StreamChecker(vector<string> &words)
    {
        trie = new Trie();
        for (auto w : words)
        {
            Trie *t = trie;
            for (int i = w.size() - 1; i >= 0; i--)
            {
                int index = w[i] - 'a';
                if (!t->vtries[index]) {
                    t->vtries[index] = new Trie();
                }
                t = t->vtries[index];
            }
            t->word = true;
        }
    }

    bool query(char letter)
    {
        Trie* t = trie;
        streamString += letter;
        for (int i = streamString.size() - 1; i >= 0; i--)
        {
            int index = streamString[i] - 'a';
            if (!t->vtries[index]) {
                return false;
            }
            t = t->vtries[index];
            if (t->word) {
                return true;
            }
        }
        
        return false;
    }
};

class StreamChecker
{
    Trie *trie;
    queue<Trie*> q;
public:
    StreamChecker(vector<string> &words)
    {
        trie = new Trie();
        for (auto w : words)
        {
            Trie *t = trie;
            for (int i = 0; i < w.size(); i++)
            {
                int index = w[i] - 'a';
                if (!t->vtries[index]) {
                    t->vtries[index] = new Trie();
                }
                t = t->vtries[index];
            }
            t->word = true;
        }
    }

    bool query(char letter)
    {
        bool ans = false;
        q.push(trie);
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Trie* t = q.front();
            q.pop();
            int index = letter - 'a';
            if (t->vtries[index]) {
                Trie* next = t->vtries[index];
                ans |= next->word;
                q.push(next);
            }
        }
        
        return ans;
    }
};


// class StreamChecker
// {
//     Trie *trie;
//     queue<Trie*> q;
// public:
//     StreamChecker(vector<string> &words)
//     {
//         trie = new Trie();
//         for (auto w : words)
//         {
//             Trie *t = trie;
//             for (int i = 0; i < w.size(); i++)
//             {
//                 if (t->tries.find(w[i]) == t->tries.end())
//                 {
//                     t->tries[w[i]] = new Trie();
//                 }

//                 t = t->tries[w[i]];
//             }
//             t->word = true;
//         }
//     }

//     bool query(char letter)
//     {
//         bool ans = false;
//         q.push(trie);
//         int count = q.size();
//         for (int i = 0; i < count; i++)
//         {
//             Trie* t = q.front();
//             q.pop();
//             if (t->tries.find(letter) != t->tries.end()) {
//                 Trie* next = t->tries[letter];
//                 ans |= next->word;
//                 if (next->tries.size() > 0) {
//                     q.push(next);
//                 }
//             }
//         }
        
//         return ans;
//     }
// };

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main() {
    vector<string> word = {"cd", "f", "kl"};
    StreamChecker sc = StreamChecker(word); 
    cout << sc.query('a') << endl;
    cout << sc.query('b') << endl;
    cout << sc.query('c') << endl;
    cout << sc.query('d') << endl;
    cout << sc.query('e') << endl;
    cout << sc.query('f') << endl;

    word = {"aa","aaab","aaaab","aaaaab"};
    sc = StreamChecker(word);
    sc.query('a');
    sc.query('a');
    sc.query('a');
}