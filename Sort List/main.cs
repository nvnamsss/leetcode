/*
Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
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
    ListNode tail = new ListNode();
    ListNode nextSubList = new ListNode();
    public int count(ListNode head)
    {
        int count = 0;
        ListNode c = head;
        while (c != null)
        {
            c = c.next;
            count++;
        }
        return count;
    }

    public ListNode split(ListNode start, int size)
    {
        ListNode midPrev = start;
        ListNode end = start.next;
        for (int loop = 0; loop < size && (midPrev.next != null || end.next != null); loop++)
        {
            if (end.next != null)
            {
                end = (end.next.next) != null ? end.next.next : end.next;
            }
            if (midPrev.next != null)
            {
                midPrev = midPrev.next;
            }

        }
        ListNode mid = midPrev.next;
        midPrev.next = null;
        nextSubList = end.next;
        end.next = null;
        // return the start of second linked list
        return mid;
    }

    public ListNode SortList(ListNode head)
    {
        /*4 2 1 3
        4, 1


        */
        if (head == null || head.next == null) return head;

        int n = count(head);
        ListNode start = head;
        ListNode dummyHead = new ListNode();
        for (int size = 1; size < n; size = size * 2)
        {
            tail = dummyHead;
            while (start != null)
            {
                if (start.next == null)
                {
                    tail.next = start;
                    break;
                }
                ListNode mid = split(start, size);
                merge(start, mid);
                start = nextSubList;
            }
            start = dummyHead.next;
        }
        return dummyHead.next;
    }

    void merge(ListNode list1, ListNode list2)
    {
        ListNode dummyHead = new ListNode();
        ListNode newTail = dummyHead;
        while (list1 != null && list2 != null)
        {
            if (list1.val < list2.val)
            {
                newTail.next = list1;
                list1 = list1.next;
                newTail = newTail.next;
            }
            else
            {
                newTail.next = list2;
                list2 = list2.next;
                newTail = newTail.next;
            }
        }
        newTail.next = (list1 != null) ? list1 : list2;
        // traverse till the end of merged list to get the newTail
        while (newTail.next != null)
        {
            newTail = newTail.next;
        }
        // link the old tail with the head of merged list
        tail.next = dummyHead.next;
        // update the old tail to the new tail of merged list
        tail = newTail;
    }

}