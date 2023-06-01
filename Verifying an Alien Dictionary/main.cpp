/*
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
*/


#include <bits/stdc++.h>
using namespace std;

class Comparer {
    unordered_map<char, int> order;
    vector<string> words;
public:
    Comparer(unordered_map<char, int>& order, vector<string> words) {
        this->order = order;
        this->words = words;
    }

    bool operator() (int& a, int& b) {
        string sa = words[a];
        string sb = words[b];
        int length = min(sa.size(), sb.size());
        for (int i = 0; i < length; i++)
        {
            int oa = order[sa[i]];
            int ob = order[sb[i]];
            if (oa != ob) {
                return oa < ob;
            }
        }
        return sa.size() < sb.size();
    }
};

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        for (int i = 0; i < order.size(); i++)
        {
            char c = order[i];
            m[c] = i;
        }
        vector<int> arr;
        for (int i = 0; i < words.size(); i++)
        {
            arr.push_back(i);
        }
        Comparer c = Comparer(m, words);
        sort(arr.begin(), arr.end(), c);

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != i) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution s;
    vector<string> words = {"hello","leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    cout << s.isAlienSorted(words, order) << endl;

    words = {"apple", "app"};
    order = "abcdefghijklmnopqrstuvwxyz";
    cout << s.isAlienSorted(words, order) << endl;
}