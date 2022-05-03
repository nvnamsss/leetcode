/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.

*/

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> group;
    vector<int> rank;
    public:
    UnionFind(int size) {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; i++)
        {
            group[i] = i;
        }
        
    }

    int find(int node) {
        if (node != group[node]) {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    bool join(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        if (group1 == group2) {
            return false;
        }
        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group2] = group1;
            rank[group1]++;
        }
        return true;
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf = UnionFind(s.size());
        for (int i = 0; i < pairs.size(); i++)
        {
            uf.join(pairs[i][0], pairs[i][1]);
        }
        vector<string> group;
        vector<int> order;
        unordered_map<int, int> existedGroup;
        for (int i = 0; i < s.size(); i++)
        {
            int g = uf.find(i);
            if (existedGroup.find(g) == existedGroup.end()) {
                existedGroup.insert({g, group.size()});
                group.push_back("");
            }

            g = existedGroup[g];
            group[g] += s[i];
            order.push_back(g);
        }

        for (int i = 0; i < order.size(); i++)
        {
            cout << order[i] << endl;
        }
                
        string ans;
        for (int i = 0; i < group.size(); i++)
        {
            sort(group[i].begin(), group[i].end(), greater<char>());
        }

        for (int i = 0; i < order.size(); i++)
        {
            ans += group[order[i]].back();
            group[order[i]].pop_back();
        }
        
        return ans;        
    }
};
