using System;

// Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// Example:
// Given a binary tree
//           1
//          / \
//         2   3
//        / \     
//       4   5    
// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

// Note: The length of path between two nodes is represented by the number of edges between them.
public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) {val = x;}
}


public class Solution {
    int max;
    public int recursive(TreeNode node, int val)
    {
        if (node == null) return val;

        val += 1;
        int left = val;
        int right = val;

        //max value = branch left + branch right
        //branch value = 

        if (node.left != null) 
        {
            left = recursive(node.left, val);            
        }

        if (node.right != null)
        {
            right = recursive(node.right, val);
        }

        max = Math.Max(max, left + right - 2 * val);
        return Math.Max(left, right);
    }

    public int DiameterOfBinaryTree(TreeNode root) {
        max = 0;
        recursive(root, 0);
        return max;
    }
}