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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head) return head;
        ListNode *cur = head;
        ListNode *ans = head;
        int count = 1;
        while (cur->next)
        {
            cur = cur->next;
            count++;
        }
        cur->next = head;
        k = count - (k % count);

        for (int i = 0; i < k; i++)
        {
            cur = cur->next;
        }
        ans = cur->next;
        cur->next = NULL;

        return ans;
    }
};