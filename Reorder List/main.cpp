/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
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
    void reorderList(ListNode *head)
    {
        stack<ListNode*> stack;
        ListNode* cur = head;
        while (cur->next) {
            stack.push(cur->next);
            cur = cur->next;
        }

        cur = head;
        int k = ceil(stack.size() / 2.0);
        for (int i = 0; i < k; i++)
        {
            ListNode* last = stack.top();
            ListNode* next = cur->next;
            last->next = next;
            cur->next = last;

            cur = next;
            stack.pop();
        }
        cur->next = NULL;
    }
};

ListNode* generate(int n) {
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for (int i = 2; i <= n; i++)
    {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    return head;
}

void log(ListNode* node) {
    ListNode* cur = node;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    Solution s;
    ListNode* node = generate(5);
    s.reorderList(node);    
    log(node);
    node = generate(16);
    s.reorderList(node);    
    log(node);
}