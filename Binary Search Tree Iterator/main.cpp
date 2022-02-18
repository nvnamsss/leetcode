#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur->left)
        {
            s.push(cur);
            cur = cur->left;
        }
        s.push(cur);

    }

    int next()
    {
        TreeNode *cur = s.top();
        int val = cur->val;
        s.pop();
        if (cur->right)
        {
            cur = cur->right;
            while (cur->left)
            {
                s.push(cur);
                cur = cur->left;
            }
            s.push(cur);

        }

        return val;
    }

    bool hasNext()
    {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    TreeNode* node = new TreeNode(7, new TreeNode(3), new TreeNode(15, new TreeNode(9), new TreeNode(20)));
    BSTIterator* bst = new BSTIterator(node);
    
}