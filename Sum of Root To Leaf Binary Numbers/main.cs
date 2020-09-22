/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
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

        public override string ToString()
        {
            return val.ToString();
        }
    }

public class Solution {
    List<List<int>> ls;
    private void preorder(List<int> l, TreeNode node)
    {
        // do some thing here
        if (node == null)
        {   
            return;
        }
        l.Add(node.val);        

        if (node.left == null && node.right == null)
        {
            //stop
            ls.Add(new List<int>(l));
        }

        if (node.left != null) preorder(node.left);
        if (node.right != null) preorder(node.right);
    }
    
    private int bti(List<int> l)
    {
        int s = 0;
        for (int loop = 0; loop < l.Count; loop++)
        {
            s += l[loop] * Math.Pow(2, loop);
        }    

        return s;
    }

    public int SumRootToLeaf(TreeNode root) {
        preorder(root);
        int s= 0;
        for (int loop = 0; loop < length; loop++)
        {
            s += bti(ls[loop]);
        }

        return s;
    }

    
}