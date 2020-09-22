/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
*/

using System;
using System.Collections.Generic;


public class TreeNode {
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
public class Solution {
    List<TreeNode> wrong;
    private void preorder(TreeNode node, TreeNode min, TreeNode max)
    {
        if (min != null && node.val <= min.val)
        {
            int temp = node.val;
            node.val = min.val;
            min.val = temp;
        }

        if (max != null && node.val >= max.val)
        {
            int temp = node.val;
            node.val = max.val;
            max.val = temp;
        }

        if (node.left != null) preorder(node.left, min, node);
        if (node.right != null) preorder(node.right, node, max);
    }

    private void preorder(TreeNode node, int min, int max) {
        if (node.val <= min || node.val >= max) wrong.Add(node);

        if (node.left != null) preorder(node.left, min, node.val);
        if (node.right != null) preorder(node.right, node.val, max);
    }
    public void RecoverTree(TreeNode root) {
        wrong = new List<TreeNode>();
        // preorder(root, int.MinValue, int.MaxValue); 
        preorder(root, null, null); 

        Console.Write($"Wrong: {wrong.Count}");
        // if (wrong.Count == 2)
        // {
        //     int temp = wrong[0].val;
        //     wrong[0].val = wrong[1].val;
        //     wrong[1].val = temp;
        // }      
    }
}