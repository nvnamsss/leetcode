/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.
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
    private static TreeNode PreorderConstruct2(int[] pre)
    {
        if (pre.Length == 0) return null;

        TreeNode node = new TreeNode(pre[0]);
        //if (root == null)
        //{
        //    root = node;
        //}

        int[] left = pre.Where(p => p < node.val).ToArray();
        int[] right = pre.Where(p => p > node.val).ToArray();

        node.left = PreorderConstruct2(left);
        node.right = PreorderConstruct2(right);

        return node;
    }
    public TreeNode BstFromPreorder(int[] preorder)
    {
        TreeNode root = PreorderConstruct2(preorder);
        return root;
    }
}