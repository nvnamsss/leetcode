/*
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val == 0
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

public class Solution
{
    int total = 0;
    int ad = 0;
    private int adjacency(TreeNode node)
    {
        int l, r;
        if (node == null) return -1;
        total++;
        // ad++;

        l = adjacency(node.left);
        r = adjacency(node.right);

        if (l == -1 && r == -1) {
            return 0;
        }

        if (l + r == -1) {
            ad = ad +1;
            return 1;
        }
    
        if (l == 0 && r == 0) {
            ad = ad + 2;
            return 1;
        }
        
        if (l * r == -1) {
            ad = ad + 1;
            return 0;
        }
        
        if (l + r == 1) {
            ad = ad + 1;
            return 1;
        }

        if (l * r == 1) {
            return 0;
        }

        Console.WriteLine("Nani");
        return 0;
        // switch (l + r) {
        //     case 0:
        //     return 1;
        //     case 1:
        //     ad = ad + 1;
        //     return 1;
        //     case 2:
        //     ad = ad - 1;
        //     return 0;
        // }

        // if (l + r == 2) {
        //     return 0;
        // }
        // if (l + r == 0) {
        //     return 1;
        // }

        // ad++;
        // return 1;

        // ad = ad + (2 - l - r);
        // return 2 - l - r;
    }

    public int MinCameraCover(TreeNode root)
    {
        int rs = 0;
        total = 0;
        ad = 0;
        adjacency(root);

        Console.WriteLine($"Total: {total} - Ad: {ad}");
        rs = total - ad;
        return rs;
    }
}