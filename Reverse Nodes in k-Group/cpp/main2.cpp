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
    ListNode *reverse(ListNode *head)
    {
        if (!head) {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return head;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *turtoise = dummy;
        ListNode *hare = dummy;

        while (hare)
        {
            for (int i = 0; i < k && hare; i++)
            {
                hare = hare->next;
            }

            if (hare)
            {
                ListNode *next = hare->next;
                hare->next = NULL;
                ListNode *tail = reverse(turtoise->next);
                turtoise->next = hare;
                tail->next = next;
                
                turtoise = tail;
                hare = tail;
            }
        }

        return dummy->next;
    }
};

ListNode *gen(int length)
{
    ListNode *dummy = new ListNode(1);
    ListNode *cur = dummy;
    for (int i = 1; i <= length; i++)
    {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    return dummy->next;
}

int main()
{
    Solution s;
    ListNode* l = gen(5);
    s.reverseKGroup(l, 2);
}