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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode* cur = head;
        while (cur) {
            ans = ans << 1;
            ans = ans | cur->val;
            cur = cur->next;
        }

        return ans;
    }
};