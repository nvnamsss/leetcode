/*
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

 

Example 1:


Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
Example 2:


Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
Each node has a unique value.
A node with a value of start exists in the tree.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int ans;
    int find(TreeNode* node, int target) {
        if (!node) {
            return -1;
        }

        if (node->val == target) {
            ans = max(ans, maxHeigh(node) - 1);
            return 0;
        }

        int l = find(node->left, target);
        int r = find(node->right, target);

        if (l != -1) {
            int h = maxHeigh(node->right);
            ans = max(ans, h + l + 1);
            return l + 1;
        }

        if (r != -1) {
            int h = maxHeigh(node->left);
            ans = max(ans, h + r + 1);
            return r + 1;
        }
        return -1;
    }

    int maxHeigh(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int l = maxHeigh(node->left);
        int r = maxHeigh(node->right);
        return max(l, r) + 1;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        ans = 0;
        find(root, start);
        return ans;
    }
};