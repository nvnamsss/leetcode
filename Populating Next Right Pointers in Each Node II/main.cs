/*
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:



Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 6000.
-100 <= node.val <= 100
*/
using System;
using System.Collections.Generic;
public class Node
{
    public int val;
    public Node left;
    public Node right;
    public Node next;
    /*  */
    public Node() { }

    public Node(int _val)
    {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
}
public class Solution
{
    private void d(Node left, Node right)
    {
        if (left == null) return;
        left.next = right;
    }

    private void rm(Node left, Node right)
    {
        if (left == null) return;
        rm(left.right, right.left);
        d(left, right);
    }

    private void r(Node left, Node right)
    {
        if (left == null) return;


        r(left.left, left.right);
        rm(left.right, right.left);
        r(right.left, right.right);
        d(left, right);
    }
    
    private Node f(Node node) {
        while (node.next != null) {
            if (node.left != null) return node.left;
            if (node.right != null) return node.right;
            node = node.next;
        }

        return null;
    }

    private void rr(Node node)
    {
        if (node == null) return;
        if (node.left != null && node.right != null)
        {
            node.left.next = node.right;
        }
        else if (node.left != null)
        {
            node.left.next = f(node);
        }
        else
        {
            node.right.next = f(node);
        }

        rr(node.left);
        rr(node.right);
    }

    public Node Connect(Node root)
    {
        Node head = root;
        Node dummy = new Node();
        Node cur = dummy;
        // rr(root);
        while (root != null) {
            if (root.left != null) {
                cur.next = root.left;
                cur = cur.next;
            }

            if (root.right != null) {
                cur.next = root.right;
                cur = cur.next;
            }

            root = root.next;
            if (root == null) {
                cur = dummy;
                root = dummy.next;
                dummy.next = null;
            }
        }

        return head;
    }
}