/*
There are n people in a social group labeled from 0 to n - 1. You are given an array logs where logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at the time timestampi.

Friendship is symmetric. That means if a is friends with b, then b is friends with a. Also, person a is acquainted with a person b if a is friends with b, or a is a friend of someone acquainted with b.

Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return -1.



Example 1:

Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
Output: 20190301
Explanation:
The first event occurs at timestamp = 20190101 and after 0 and 1 become friends we have the following friendship groups [0,1], [2], [3], [4], [5].
The second event occurs at timestamp = 20190104 and after 3 and 4 become friends we have the following friendship groups [0,1], [2], [3,4], [5].
The third event occurs at timestamp = 20190107 and after 2 and 3 become friends we have the following friendship groups [0,1], [2,3,4], [5].
The fourth event occurs at timestamp = 20190211 and after 1 and 5 become friends we have the following friendship groups [0,1,5], [2,3,4].
The fifth event occurs at timestamp = 20190224 and as 2 and 4 are already friends anything happens.
The sixth event occurs at timestamp = 20190301 and after 0 and 3 become friends we have that all become friends.
Example 2:

Input: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4
Output: 3


Constraints:

2 <= n <= 100
1 <= logs.length <= 104
logs[i].length == 3
0 <= timestampi <= 109
0 <= xi, yi <= n - 1
xi != yi
All the values timestampi are unique.
All the pairs (xi, yi) occur at most one time in the input.

*/

#include <bits/stdc++.h>
using namespace std;
class UnionFind
{
    vector<int> group;
    vector<int> rank;

public:
    UnionFind(int size)
    {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; i++)
        {
            group[i] = i;
        }
    }

    int find(int node)
    {
        if (node != group[node])
        {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    bool join(int node1, int node2)
    {
        int group1 = find(group[node1]);
        int group2 = find(group[node2]);
        if (group1 == group2)
        {
            return false;
        }

        if (rank[group1] > rank[group2])
        {
            group[group2] = group1;
        }
        else if (rank[group1] < rank[group2])
        {
            group[group1] = group2;
        }
        else
        {
            group[group2] = group1;
            rank[group1]++;
        }
        return true;
    }
};

class Solution
{
public:
    int earliestAcq(vector<vector<int>> &logs, int n)
    {
        int components = n;
        UnionFind uf = UnionFind(n);
        sort(logs.begin(), logs.end());
        for (int i = 0; i < logs.size(); i++)
        {
            if (uf.join(logs[i][1], logs[i][2]))
            {
                components--;
                if (components == 1)
                {
                    return logs[i][0];
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> logs = {{7, 3, 2}, {2, 0, 4}, {9, 6, 4}, {4, 1, 3}, {6, 4, 3}, {3, 0, 2}, {11, 5, 1}, {8, 6, 3}, {1, 6, 5}, {0, 4, 2}};
    s.earliestAcq(logs, 7);
    return 0;
}