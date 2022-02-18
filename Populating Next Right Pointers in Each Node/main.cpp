#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<Node *> q;
        queue<Node *> q2;
        q.push(root);
        while (!q.empty())
        {
            Node *last = NULL;
            while (!q.empty())
            {
                Node *node = q.front();
                q.pop();
                if (node->right)
                {
                    q2.push(node->right);
                }

                if (node->left)
                {
                    q2.push(node->left);
                }

                node->next = last;
                last = node;
            }

            while (!q2.empty())
            {
                q.push(q2.front());
                q2.pop();
            }
        }

        return root;
    }
};

Node *binaryTree(int l)
{
    if (l <= 0)
        return NULL;
    Node *node = new Node();
    node->left = binaryTree(l - 1);
    node->right = binaryTree(l - 1);
    return node;
}

int main()
{
    Node *node = binaryTree(3);
    Solution s;
    s.connect(node);
}