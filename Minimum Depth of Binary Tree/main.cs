/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000
*/
using System;
using System.Collections.Generic;

public class TreeNode{
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
    private int minDepth(TreeNode root, int d)
    {
        if (root.left == null && root.right == null) return d;
        int dl = root.left != null ? minDepth(root.left, d + 1) : int.MaxValue;
        int dr = root.right != null ? minDepth(root.right, d + 1) : int.MaxValue;
        return Math.Min(dl, dr);
    }

    public int MinDepth(TreeNode root) {
        if (root == null) return 0;
        return minDepth(root, 1);
    }
}