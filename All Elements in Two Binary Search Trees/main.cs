/*
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].
*/

using System;
using System.Collections;
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
    //the problem is merge two Binary Search Tree to a Binary Search Tree
    //or we can easily convert tree to sorted array then merge two sorted array
    public TreeNode Merge(TreeNode root1, TreeNode root2)
    {
        
    }

    private void InorderIterate(Queue<int> arr, TreeNode node)
    {
        if (node.left != null) InorderIterate(arr, node.left);
        arr.Enqueue(node.val);
        if (node.right != null) InorderIterate(arr, node.right);
    }
    
    public IList<int> GetAllElements(TreeNode root1, TreeNode root2) {
        Queue<int> q1 = new Queue<int>();
        InorderIterate(q1, root1);
        Queue<int> q2 = new Queue<int>();
        InorderIterate(q2, root2);

        List<int> rs = new List<int>(q1.Count + q2.Count);
        while (true)
        {
            if (q1.Count == 0 && q2.Count == 0) break;

            
            if (q1.Count > 0 && (q2.Count == 0 || q1.Peek() < q2.Peek()))
            {
                rs.Add(q1.Dequeue());
                continue;
            }

            if (q2.Count > 0 && (q1.Count == 0 || q2.Peek() < q1.Peek()))
            {
                rs.Add(q2.Dequeue());
                continue;
            }
        }

        return rs;
    }
}