/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/
using System;
using System.Collections.Generic;
public class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int val = 0, ListNode next =null) {
        this.val = val;
        this.next = next;
    }
}
public class Solution {
    public ListNode DeleteDuplicates(ListNode head) {
ListNode current = head;
            ListNode previous = head;
            HashSet<int> set = new HashSet<int>();
            while (current != null)
            {
                if (!set.Contains(current.val))
                {
                    set.Add(current.val);
                    previous = current;
                }
                else
                {
                    previous.next = current.next;
                }

                current = current.next;
            }

        return head;
    }
}