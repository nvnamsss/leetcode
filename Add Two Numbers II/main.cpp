/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.


Follow up: Could you solve it without reversing the input lists?
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
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1;
        stack<int> s2;

        ListNode *c = l1;
        while (c)
        {
            s1.push(c->val);
            c = c->next;
        }

        c = l2;
        while (c)
        {
            s2.push(c->val);
            c = c->next;
        }

        ListNode *head = NULL;
        int r = 0;
        while (!s1.empty() && !s2.empty())
        {
            int v = s1.top() + s2.top() + r;
            r = v / 10;
            v = v % 10;

            head = new ListNode(v, head);

            s1.pop();
            s2.pop();
        }

        while (!s1.empty())
        {
            int v = s1.top() + r;
            r = v / 10;
            v = v % 10;
            head = new ListNode(v, head);
            s1.pop();
        }

        while (!s2.empty())
        {
            int v = s2.top() + r;
            r = v / 10;
            v = v % 10;
            head = new ListNode(v, head);
            s2.pop();
        }

        if (r > 0)
        {
            head = new ListNode(r, head);
        }

        return head;
    }
};