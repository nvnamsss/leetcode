/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    void swap(ListNode *head)
    {
        ListNode *t1 = head->next;
        ListNode *t2 = head->next->next;
        t1->next = t2->next;
        t2->next = t1;
        head->next = t2;
    }

public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *turtoise = dummy;
        ListNode *hare = turtoise;
        while (hare)
        {
            for (int i = 0; i < 2 && hare; i++)
            {
                hare = hare->next;
            }

            if (hare)
            {
                hare = turtoise->next;
                swap(turtoise);
                turtoise = hare;
            }
        }

        return dummy->next;
    }
};