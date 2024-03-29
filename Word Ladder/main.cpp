/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.



Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int bidirectionalBfs(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, vector<int>> graph;
        unordered_set<string> s;
        for (int i = 0; i < wordList.size(); i++)
        {
            string word = wordList[i];
            s.insert(word);
            for (int j = 0; j < word.size(); j++)
            {
                char c = word[j];
                word[j] = '*';
                graph[word].push_back(i);
                word[j] = c;
            }
        }
        if (s.find(endWord) == s.end()) {
            return 0;
        }
        queue<int> qb;
        vector<bool> visitedb = vector<bool>(wordList.size(), false);
        for (int i = 0; i < beginWord.size(); i++)
        {
            char c = beginWord[i];
            beginWord[i] = '*';
            vector<int> edges = graph[beginWord];
            for (int j = 0; j < edges.size(); j++)
            {
                qb.push(edges[j]);
            }
            beginWord[i] = c;
        }

        queue<int> qe;
        vector<bool> visitede = vector<bool>(wordList.size(), false);
        for (int i = 0; i < endWord.size(); i++)
        {
            char c = endWord[i];
            endWord[i] = '*';
            vector<int> edges = graph[endWord];
            for (int j = 0; j < edges.size(); j++)
            {
                qe.push(edges[j]);
            }
            endWord[i] = c;
        }

        int tb = 0;
        int te = 0;
        while (!qb.empty())
        {
            tb++;
            int count = qb.size();
            for (int i = 0; i < count; i++)
            {
                int index = qb.front();
                qb.pop();
                visitedb[index] = true;
                string word = wordList[index];
                if (visitede[index])
                {
                    return tb + te;
                }

                for (int j = 0; j < word.size(); j++)
                {
                    char c = word[j];
                    word[j] = '*';
                    vector<int> edges = graph[word];
                    for (int k = 0; k < edges.size(); k++)
                    {
                        if (!visitedb[edges[k]])
                        {
                            qb.push(edges[k]);
                        }
                    }

                    word[j] = c;
                }
            }
            te++;
            count = qe.size();
            for (int i = 0; i < count; i++)
            {
                int index = qe.front();
                qe.pop();
                visitede[index] = true;
                string word = wordList[index];
                if (visitedb[index])
                {
                    return tb + te;
                }
                for (int j = 0; j < word.size(); j++)
                {
                    char c = word[j];
                    word[j] = '*';
                    vector<int> edges = graph[word];
                    for (int k = 0; k < edges.size(); k++)
                    {
                        if (!visitede[edges[k]])
                        {
                            qe.push(edges[k]);
                        }
                    }

                    word[j] = c;
                }
            }

        }

        return 0;
    }

    int bfs(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, vector<int>> graph;

        for (int i = 0; i < wordList.size(); i++)
        {
            string word = wordList[i];
            for (int j = 0; j < word.size(); j++)
            {
                char c = word[j];
                word[j] = '*';
                graph[word].push_back(i);
                word[j] = c;
            }
        }

        queue<int> q;
        vector<bool> visited = vector<bool>(wordList.size(), false);

        for (int i = 0; i < beginWord.size(); i++)
        {
            char c = beginWord[i];
            beginWord[i] = '*';
            vector<int> edges = graph[beginWord];
            for (int j = 0; j < edges.size(); j++)
            {
                q.push(edges[j]);
            }
            beginWord[i] = c;
        }

        int ans = 0;
        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                int index = q.front();
                q.pop();
                visited[index] = true;
                string word = wordList[index];
                if (word == endWord)
                {
                    return ans + 2;
                }

                for (int j = 0; j < word.size(); j++)
                {
                    char c = word[j];
                    word[j] = '*';
                    vector<int> edges = graph[word];
                    for (int k = 0; k < edges.size(); k++)
                    {
                        if (!visited[edges[k]])
                        {
                            q.push(edges[k]);
                        }
                    }

                    word[j] = c;
                }
            }

            ans++;
        }

        return 0;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        return bidirectionalBfs(beginWord, endWord, wordList);
    }
};

int main()
{
    Solution s;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << s.ladderLength("hit", "cog", wordList) << endl;

    wordList = {"hot", "dot", "dog", "lot", "log"};
    cout << s.ladderLength("hit", "cog", wordList) << endl;
}