// Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

public class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int val = 0, ListNode next = null)
    {
        this.val = val;
        this.next = next;
    }
}

public class Solution {
    public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;

        ListNode l = null;
        while (l1 != null || l2 != null)
        {
            if (l2 == null || l1.val < l2.val)
            {
                l = new ListNode(l1.val);
                l1 = l1.next;
            }
            else if (l1 == null || l2.val < l1.val) {
                l = new ListNode(l2.val);
                l2 = l2.next;
            }

            l = l.next;
        }

        return l;
    }
}