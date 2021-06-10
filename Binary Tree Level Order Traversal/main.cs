/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
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
public class Solution
{
    List<IList<int>> rs;
    private void levelOrder(int level, TreeNode node) {
        if (node == null) return;
        if (rs.Count == level) rs.Add(new List<int>());
        rs[level].Add(node.val);

        levelOrder(level + 1, node.left);
        levelOrder(level + 1, node.right);
    }

    public IList<IList<int>> LevelOrder(TreeNode root)
    {
        rs = new List<IList<int>>();
        levelOrder(0, root);

        return rs;
    }
}