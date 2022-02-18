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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;

        ListNode* ll1 = l1;
        ListNode* ll2 = l2;

        while (ll1 != NULL && ll2 != NULL) {
            if (ll1->val < ll2->val) {
                cur->next = new ListNode(ll1->val);
                ll1 = ll1->next;
            } else {
                cur->next = new ListNode(ll2->val);
                ll2 = ll2->next;
            }

            cur = cur->next;
        }
        
        while (ll1 != NULL) {
            cur->next = new ListNode(ll1->val);
            ll1 = ll1->next;
            cur = cur->next;
        }

        while (ll2 != NULL) {
            cur->next = new ListNode(ll2->val);
            ll2 = ll2->next;
            cur = cur->next;
        }

        return head->next;
    }
};