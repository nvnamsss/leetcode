/*
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

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
    ListNode mid(ListNode head)
    {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;

        }
        if (fast != null)
        {
            slow = slow.next;
        }
        return slow;
    }

    ListNode reverse(ListNode node) {
        ListNode h = null;
        ListNode head = node;
        while (head != null) {
            ListNode next = head.next;
            head.next = h;
            h = head;
            head = next;
        }

        return h;
    }


    public bool IsPalindrome(ListNode head)
    {
        // 1 7 8 9 9 8 7 1
        ListNode m = mid(head);
        ListNode r = reverse(m);
        ListNode h = head;

        while (r != null) {
            if (r.val != h.val) return false;
            r = r.next;
            h = h.next;
        }

        return true;
    }
}