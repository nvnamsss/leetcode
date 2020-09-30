/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

using System;
using System.Collections.Generic;
using System.Linq;

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

public class Solution
{
    public static int[] SubArray(int[] data, int index, int length)
{
    int[] result = new int[length];
    Array.Copy(data, index, result, 0, length);
    return result;
}

    public TreeNode Create(int[] nums, int start, int end)
    {
        if (start > end) return null;
        int mid = start + (end - start) / 2;
        TreeNode node = new TreeNode(nums[mid]);

        node.left = Create(nums, start, mid - 1);
        node.right = Create(nums, mid + 1, end);

        return node;
    }

    public TreeNode SortedArrayToBST(int[] nums)
    {
        TreeNode root = Create(nums, 0, nums.Length - 1);
        return root;
    }
}