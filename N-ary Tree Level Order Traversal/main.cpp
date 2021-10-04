#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> rs;
        if (root == NULL) return rs;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> subrs;
            vector<Node *> nextLevel;

            while (!q.empty())
            {
                Node *node = q.front();
                q.pop();
                subrs.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++)
                {
                    nextLevel.push_back(node->children[i]);
                }
            }

            for (int i = 0; i < nextLevel.size(); i++)
            {
                q.push(nextLevel[i]);
            }
            rs.push_back(subrs);
        }

        return rs;
    }
};
