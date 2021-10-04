/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
 

Follow-up: Can you solve the problem in O(1) extra memory space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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

    void reverse(ListNode* head, int n) {
        
    }
public:
    ListNode* sample1(int length) {
        ListNode* node = new ListNode(1);
        ListNode* cur = node;
        for (int i = 2; i <= length; i++)
        {
            cur->next = new ListNode(i);
            cur = cur->next;
        }

        return node;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        /*
        Recursively solve the subproblem by k / 2
        easily see that for reversing a list node, we reverse a half of list then using two pointer to swap the
        first half and second half listnode
        */

        if (k < 2) return head;
        ListNode* cur = head;
        ListNode* first;
        ListNode* mid;
        int n = 0;
        int kd2 = k / 2;
        while (cur != NULL) {
            if (n == kd2) {
                mid = cur;
                ListNode* next = reverseKGroup(cur->next, kd2);
                ListNode* p1 = first;
                ListNode* p2 = cur;

                while (n > 0) {
                    // swap here   
                    ListNode* t1 = p1->next;
                    ListNode* t2 = p2->next;

                    // originally, the order is p1 -> t1 -> t1.next, p2 -> t2 -> t2.next
                    // we want to get this order p1 -> t2 -> t1.next, p2 -> t1 -> t2.next

                    ListNode* t = t1->next;
                    t1->next = t2->next;
                    t2->next = t;

                    p1->next = t2;
                    p2->next = t1;

                    // then we go to the next pointer, it means t1 and t2
                    p1 = t2;
                    p2 = t1;

                    n--;
                }

                
            }

            n++;
            cur = cur -> next;
        }

        return first;
    }


};

int main() {
    Solution s;
    ListNode* sample = s.sample1(2);
    s.reverseKGroup(sample, 2);

    sample = s.sample1(5);
    s.reverseKGroup(sample, 5);

    return 1;
}
