/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

using System;
using System.Collections.Generic;
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

    public override string ToString()
    {
        return val.ToString();
    }
}

public class Solution
{
    bool result;
    private void preorder(TreeNode node, TreeNode min, TreeNode max)
    {
        if (node == null) return;

        if (min != null && node.val <= min.val) result = false;
        if (max != null && node.val >= max.val) result = false;

        preorder(node.left, min, node);
        preorder(node.right, node, max);
    }

    public bool IsValidBST(TreeNode root)
    {
        result = true;
        preorder(root, null, null);

        return result;
    }
}