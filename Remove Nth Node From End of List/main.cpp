/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.



Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz


Follow up: Could you do this in one pass?
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
    ListNode *secondTry(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *turtoise = dummy;
        ListNode *hare = turtoise;
        for (int i = 0; i < n; i++)
        {
            hare = hare->next;
        }
        while (hare->next)
        {
            turtoise = turtoise->next;
            hare = hare->next;
        }

        turtoise->next = turtoise->next->next;
        return dummy->next;
    }
    ListNode *firstTry(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *turtoise = dummy;

        while (true)
        {
            int count = 0;
            ListNode *hare = turtoise->next;

            while (count < n)
            {
                hare = hare->next;
                count++;
            }

            if (hare == NULL)
            {
                turtoise->next = turtoise->next->next;
                break;
            }
            else
            {
                turtoise = turtoise->next;
            }
        }

        return dummy->next;
    }
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        return secondTry(head, n);
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    s.removeNthFromEnd(head, 2);
}