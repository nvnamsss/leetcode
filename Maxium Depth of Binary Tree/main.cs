/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/

public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
}

public class Solution
{
    private int depth(TreeNode root, int d)
        {
            int dl = d;
            int dr = d;
            if (root.left != null) dl = depth(root.left, dl + 1);
            if (root.right != null) dr = depth(root.right, dr + 1);

            return Math.Max(dl, dr);
        }

        public int MaxDepth(TreeNode root)
        {
            int d = depth(root, 0);
            return d;
        }
}