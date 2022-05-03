/*
Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#').

You are given a string array sentences and an integer array times both of length n where sentences[i] is a previously typed sentence and times[i] is the corresponding number of times the sentence was typed. For each input character except '#', return the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed.

Here are the specific rules:

The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same hot degree, use ASCII-code order (smaller one appears first).
If less than 3 hot sentences exist, return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
Implement the AutocompleteSystem class:

AutocompleteSystem(String[] sentences, int[] times) Initializes the object with the sentences and times arrays.
List<String> input(char c) This indicates that the user typed the character c.
Returns an empty array [] if c == '#' and stores the inputted sentence in the system.
Returns the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed. If there are fewer than 3 matches, return them all.
 

Example 1:

Input
["AutocompleteSystem", "input", "input", "input", "input"]
[[["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]], ["i"], [" "], ["a"], ["#"]]
Output
[null, ["i love you", "island", "i love leetcode"], ["i love you", "i love leetcode"], [], []]

Explanation
AutocompleteSystem obj = new AutocompleteSystem(["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]);
obj.input("i"); // return ["i love you", "island", "i love leetcode"]. There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored.
obj.input(" "); // return ["i love you", "i love leetcode"]. There are only two sentences that have prefix "i ".
obj.input("a"); // return []. There are no sentences that have prefix "i a".
obj.input("#"); // return []. The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search.
 

Constraints:

n == sentences.length
n == times.length
1 <= n <= 100
1 <= sentences[i].length <= 100
1 <= times[i] <= 50
c is a lowercase English letter, a hash '#', or space ' '.
Each tested sentence will be a sequence of characters c that end with the character '#'.
Each tested sentence will have a length in the range [1, 200].
The words in each input sentence are separated by single spaces.
At most 5000 calls will be made to input.

*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> pairs;

class Comparision
{
public:
    bool operator()(pairs &a, pairs &b)
    {
        if (a.first == b.first)
            return a.second.compare(b.second) >= 0;
        return a.first < b.first;
    }
};

class Trie
{
    unordered_map<char, Trie *> tries;
    bool complete;
    int times;

    void words(priority_queue<pairs, vector<pairs>, Comparision> &vs, string s)
    {
        if (complete)
        {
            vs.push({times, s});
        }

        for (auto &&it : tries)
        {
            it.second->words(vs, s + it.first);
        }
    }

public:
    Trie()
    {
        complete = false;
        times = 0;
    }

    Trie *get(char c)
    {
        if (tries.find(c) == tries.end())
            return NULL;
        return tries[c];
    }

    void init(string &sentence)
    {
        Trie *t = this;
        for (auto &&c : sentence)
        {
            if (t->tries.find(c) == t->tries.end())
            {
                t->tries[c] = new Trie();
            }

            t = t->tries[c];
        }

        t->complete = true;
        t->times++;
    }
    void init(vector<string> &sentences, vector<int> &times)
    {
        for (int i = 0; i < sentences.size(); i++)
        {
            Trie *t = this;
            for (auto &&c : sentences[i])
            {
                if (t->tries.find(c) == t->tries.end())
                {
                    t->tries[c] = new Trie();
                }

                t = t->tries[c];
            }

            t->complete = true;
            t->times = times[i];
        }
    }

    priority_queue<pairs, vector<pairs>, Comparision> words(string prefix)
    {
        priority_queue<pairs, vector<pairs>, Comparision> vs;
        words(vs, prefix);
        return vs;
    }
};

class AutocompleteSystem
{
    Trie *t;
    Trie *cur;
    string prefix;

public:
    AutocompleteSystem(vector<string> &sentences, vector<int> &times)
    {
        t = new Trie();
        cur = t;
        t->init(sentences, times);
    }

    vector<string> input(char c)
    {
        if (c == '#')
        {
            t->init(prefix);
            cur = t;
            prefix = "";
            return {};
        }
        prefix += c;

        if (!cur)
        {
            return {};
        }

        cur = cur->get(c);

        if (!cur)
        {
            return {};
        }

        vector<string> ans;
        priority_queue<pairs, vector<pairs>, Comparision> pq = cur->words(prefix);
        int count = pq.size();
        count = min(3, count);
        for (int i = 0; i < count; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

void print(vector<string> vs)
{
    for (int i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << " - ";
    }
    cout << endl;
}

int main()
{
    vector<string> sentences = {"i love you", "island", "iroman", "i love leetcode"};
    vector<int> times = {5, 3, 2, 2};
    AutocompleteSystem as = AutocompleteSystem(sentences, times);
    cout << sentences[2].compare(sentences[3]) << endl;
    print(as.input('i'));
    print(as.input(' '));
    print(as.input('a'));
    print(as.input('#'));

    print(as.input('i'));
    print(as.input(' '));
    print(as.input('a'));
    print(as.input('#'));

    print(as.input('i'));
    print(as.input(' '));
    print(as.input('a'));
    print(as.input('#'));

    sentences = {"abc", "abbc", "a"};
    times = {3,3,3};
    as = AutocompleteSystem(sentences, times);
    print(as.input('b'));
    print(as.input('c'));
    print(as.input('#'));

    print(as.input('b'));
    print(as.input('c'));
    print(as.input('#'));
    
}