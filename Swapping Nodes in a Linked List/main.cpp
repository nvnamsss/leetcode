/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* tortoise = dummy;
        ListNode* hare = dummy;
        ListNode* n1 = dummy;

        for (int i = 1; i < k; i++)
        {
            n1 = n1->next;
            hare = hare->next;
        }
        
        while (!hare) {
            tortoise = tortoise->next;
            hare = hare->next;
        }

        ListNode* v1 = n1->next;
        ListNode* v2 = tortoise->next;
        ListNode* v1n = v1->next;
        v1->next = v2->next;
        v2->next = v1n;
        n1->next = v2;
        tortoise->next = v1;
        // n1->next = n2->next;
        // n2->next = n1->next;

        return dummy->next;
    }
};