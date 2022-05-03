/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // a -> b -> c -> d -> e
        // n1 = a n2 = b n3 = c
        // n2->next = n1
        // n1 = n2, n2 = n3, n3 = n2->next
        int i = 0;
        ListNode* dummy = new ListNode(0, head);
        ListNode* n1 = dummy; 
        ListNode* n2; 
        ListNode* n3; 
        for (i = 1; i < left; i++)
        {
            n1 = n1->next;
        }

        ListNode* h1 = n1;
        ListNode* h2 = n2;

        n2 = n1->next;
        n3 = n2->next;
        
        while (i < right) {
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            n3 = n2->next;

            i++;
        }
        ListNode* t1 = n2;
        ListNode* t2 = n3;

        h2->next = t2;
        t1->next = h1;

        return dummy->next;
    }
};

ListNode* gen(int count) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int i = 0; i < count; i++)
    {
        cur->next = new ListNode(i + 1);
        cur = cur->next;
    }
    
    return dummy->next;
}

void print(ListNode* h) {
    ListNode* cur = h;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
int main() {
    Solution s;
    ListNode* h = gen(5);
    s.reverseBetween(h);
}