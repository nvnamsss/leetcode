/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
*/
using System;
public class Solution {
        private int depth(TreeNode root, int d)
        {
            int dl = d;
            int dr = d;
            if (root.left != null) dl = depth(root.left, dl + 1);
            if (root.right != null) dr = depth(root.right, dr + 1);

            return Math.Max(dl, dr);
        }

    private bool balanced(TreeNode root)
    {
        if (root == null) return true;
        int dl = 0, dr = 0;
        
        if (root.left != null)
        {
            dl = depth(root.left, 1);
        }

        if (root.right != null)
        {
            dr = depth(root.right, 1);
        }

        return Math.Abs(dl - dr) <= 1 && balanced(root.left) && balanced(root.right);
    }

    public bool IsBalanced(TreeNode root) {
        //for determining a tree is balanced, must we ensure that the level of of branch are never be exceed 2
        if (root == null) return false;

  
        return balanced(root);       
    }
}