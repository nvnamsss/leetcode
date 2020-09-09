/*
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.
This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
*/

using System;
using System.Collections.Generic;
public class Solution {
    List<int> l;
    int min;
    private void inorder(TreeNode node)
    {
        // int dif = Math.min(min, Math.Abs(prev - node.val));
        if (node.left != null) inorder(node.left);
        l.Add(node.val);
        if (node.right != null) inorder(node.right);
    }


    public int MinDiffInBST(TreeNode root) {
        l = new List<int>();
        min = int.MaxValue;
        if (root == null) return 0;
        inorder(root);
        // if (root.left != null) inorder(root.left);
        // if (root.right != null) inorder(root.right);
        for (int loop = 0; loop < l.Count - 1; loop++)
        {
           if (l[loop + 1] - l[loop] < min)
           {
               min = l[loop + 1] - l[loop];
           } 
        }

        return min;
    }
}