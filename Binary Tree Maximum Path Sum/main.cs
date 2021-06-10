
/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 

A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000
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
}

public class TreeBuilder {
    private static TreeNode build(int?[] values, int index) {
        if (index >= values.Length || values[index] == null ) {
            return null;
        }

        TreeNode node = new TreeNode(values[index].Value);
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        node.left = build(values, left);
        node.right = build(values, right);        

        return node;
    }

    public static TreeNode Build(int?[] values) {
        return build(values, 0);
    }
}

public class Solution
{
    int max;
    private int Recursive2(TreeNode root) {
        int left = 0;
        int right = 0;
        if (root.left != null) left = Recursive2(root.left);
        if (root.right != null) right = Recursive2(root.right);

        int rt = Math.Max(root.val,
         Math.Max(root.val + left, root.val + right));

        // why must separate, I forgot the key
        // the above is local max while the below is global?
        // the answer is if we combine the above with below, the leaf node will take both value of left and right
        // while we are finding the path thus the above is the maximum path we can find from the descendant
        max = Math.Max(max, rt);
        max = Math.Max(max, root.val + left + right);
        return rt;
    }


    public int MaxPathSum(TreeNode root)
    {
        max = int.MinValue;
        Recursive2(root);

        return max;
    }
}