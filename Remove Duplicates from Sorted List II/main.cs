/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/

using System;
using System.Collections.Generic;

public class ListNode
{
    public int val;
    public ListNode next;
    public ListNode(int val = 0, ListNode next = null)
    {
        this.val = val;
        this.next = next;
    }
}

public class Solution
{
    public ListNode DeleteDuplicates(ListNode head)
    {
        ListNode sentinel = new ListNode(-1000, head);
        ListNode current = sentinel;
        ListNode lastHead = null;

        while (current != null)
        {
            bool duplicate = false;
            while (current.next != null && current.val == current.next.val)
            {
                current = current.next;
                duplicate = true;
            }

            if (duplicate)
                lastHead.next = current.next;
            else
                lastHead = current;

            // lastHead = current.next;
            current = current.next;
        }

        return sentinel.next;
    }
}