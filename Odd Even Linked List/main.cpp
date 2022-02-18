/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

n == number of nodes in the linked list
0 <= n <= 104
-106 <= Node.val <= 106
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
    ListNode *oddEvenList(ListNode *head)
    {
        // 0 1 2 3 4 5 6
        // 0 2 4 6 1 3 5
        // 0 1 2 3 4 5 6 7
        // 0 2 4 6 1 3 5 7
        if (!head) {
            return NULL;
        }
        int index = 1;
        ListNode *turtoise = head;
        ListNode *hare = head;
        while (hare->next)
        {
            for (int i = 0; i < index && hare->next; i++)
            {
                hare = hare->next;
            }

            // swap here
            if (hare->next)
            {
                ListNode *t = hare->next;
                hare->next = t->next;
                t->next = turtoise->next;
                turtoise->next = t;
                hare = turtoise->next;
                turtoise = hare;
            }
            //

            index++;
        }

        return head;
    }
};

ListNode *gen(int count)
{
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;

    for (int i = 0; i < count; i++)
    {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    return dummy->next;
}

void print(ListNode *head)
{
    ListNode *cur = head;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    Solution s;
    ListNode *head = gen(8);
    ListNode *rs = s.oddEvenList(head);
    print(rs);

    head = gen(1);
    rs = s.oddEvenList(head);
    print(rs);

    head = gen(0);
    rs = s.oddEvenList(head);
    print(rs);
}