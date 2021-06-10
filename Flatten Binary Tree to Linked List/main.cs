
/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 

Follow up: Can you flatten the tree in-place (with O(1) extra space)?
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
using System;

public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}


public class Solution
{
    private TreeNode flatting(TreeNode node) {
        TreeNode head = node.left;
        TreeNode end = node;
        TreeNode left = node.left;
        TreeNode right = node.right;

        if (left != null) {
            end = flatting(head);
            head = left;
        }

        if (right != null) {
            TreeNode rend = flatting(right);
            end.right = right;
            end = rend;
            if (head == null) head = right;
        }

        node.right = head;
        node.left = null;
        return end;
    }
    public void Flatten(TreeNode root)
    {
        if (root == null) return;
        flatting(root);
        
    }   

    TreeNode prev;
    public void Flatten2(TreeNode node) {
        if (node == null) return;

        Flatten2(node.right);
        Flatten2(node.left);

        node.right = prev;
        node.left = null;
        prev = node;
    }
}