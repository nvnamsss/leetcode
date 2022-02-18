/*
You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.

The kth ancestor of a tree node is the kth node in the path from that node to the root node.

Implement the TreeAncestor class:

TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.
 

Example 1:


Input
["TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"]
[[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]
Output
[null, 1, 0, -1]

Explanation
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
treeAncestor.getKthAncestor(3, 1); // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2); // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3); // returns -1 because there is no such ancestor
 

Constraints:

1 <= k <= n <= 5 * 104
parent.length == n
parent[0] == -1
0 <= parent[i] < n for all 0 < i < n
0 <= node < n
There will be at most 5 * 104 queries.
*/

#include <bits/stdc++.h>
using namespace std;

class TreeAncestor
{
    vector<vector<int>> sparseTable;
    vector<int> height;

public:
    TreeAncestor(int n, vector<int> &parent)
    {
        height = vector<int>(n, 0);
        sparseTable = vector<vector<int>>(n);
        sparseTable[0] = vector<int>(1, -1);
        for (int i = 1; i < parent.size(); i++)
        {
            height[i] = height[parent[i]] + 1;
            sparseTable[i] = vector<int>(height[i]);
            sparseTable[i][0] = parent[i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < height[i]; j++)
            {
                int p = parent[j];
                sparseTable[i][j] = sparseTable[p][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        if (height[node] < k) {
            return -1;
        }
        return sparseTable[node][k - 1];
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

int main()
{
    vector<int> parent = {-1, 0, 0, 0, 3};
    TreeAncestor ta = TreeAncestor(5, parent);
    cout << ta.getKthAncestor(1, 5) << endl;
    cout << ta.getKthAncestor(3, 2) << endl;
    cout << ta.getKthAncestor(0, 1) << endl;
    cout << ta.getKthAncestor(3, 1) << endl;
    cout << ta.getKthAncestor(3, 5) << endl;

    parent = {-1, 0, 1, 2, 3, 4, 5};
    ta = TreeAncestor(7, parent);
}