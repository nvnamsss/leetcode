/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head != NULL && head->val == val)
        {
            head = head->next;
        }

        ListNode *cur = head;

        while (cur != NULL && cur->next != NULL)
        {
            ListNode *next = cur->next;

            if (next->val == val)
            {
                cur->next = next->next;
                continue;
            }

            cur = cur->next;
        }

        return head;
    }

    TreeNode* prev;
    void flatten(TreeNode *root)
    {
        if (root == NULL) return;
        
        TreeNode* left= root->left;
        TreeNode* right = root->right;
        flatten(right);
        flatten(left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }

};

TreeNode* example1() {
    TreeNode* n2 = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    TreeNode* n3 = new TreeNode(5, NULL, new TreeNode(6));
    TreeNode* n = new TreeNode(1, n2, n3);
    return n;
}

int main() {
    Solution s; 
    s.flatten(example1());
}

