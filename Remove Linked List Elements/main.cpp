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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *cur = dummy;

        while (cur != NULL && cur->next != NULL)
        {
            ListNode *next = cur->next;

            if (next->val == val) {
                cur->next = next->next;
            } else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};