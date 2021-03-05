/*
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

 

Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
Example 2:


Input: root = [5,1,7]
Output: [1,null,5,null,7]
 

Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000
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
    List<int> arr = new List<int>();
    TreeNode head;
    TreeNode node;
    private void recursive(TreeNode root)
    {
        if (root.left != null) recursive(root.left);
        arr.Add(root.val);
        // if (head == null) {
        //     head = new TreeNode(root.val);
        //     node = head;
        // } else if (node.right == null) {
        //     node.right = new TreeNode(root.val);
        //     node = node.right;
        // }

        // node.val = root.val;
        // node.right = new TreeNode();
        // node = node.right;
        if (root.right != null) recursive(root.right);
    }

    public TreeNode IncreasingBST(TreeNode root)
    {
        arr = new List<int>();
        head = null;
        node = null;
        recursive(root);

        head = new TreeNode(arr[0]);
        node = head;
        for (int loop = 1; loop < arr.Count; loop++)
        {
            node.right = new TreeNode(arr[loop]);
            node = node.right;
        }
        return head;
    }
}