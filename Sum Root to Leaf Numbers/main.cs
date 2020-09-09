/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
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
    List<int> l;
    private void preorder(int val, TreeNode node)
    {
        if (node.left == null && node.right == null)
        {
            l.Add(val);
            return;
        }

        if (node.left != null) preorder(val * 10 + node.val, node.left);
        if (node.right != null) preorder(val * 10 + node.val, node.right);
    }

    public int SumNumbers(TreeNode root)
    {
        l = new List<int>();
        if (root == null) return 0;
        preorder(root.val, root);
        int s = 0;
        for (int loop = 0; loop < l.Count; loop++)
        {
            s += l[loop];
        }

        return s;
    }
}