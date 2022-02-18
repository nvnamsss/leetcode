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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(-200, head);
        ListNode *turtoise = dummy;
        ListNode *hare = turtoise->next;
        while (hare)
        {
            bool duplicate = false;
            while (hare->next && hare->next->val == turtoise->next->val)
            {
                hare = hare->next;
                duplicate = true;
            }

            if (duplicate)
            {
                turtoise->next = hare->next;
            }
            else
            {
                turtoise = hare;
            }
            hare = turtoise->next;
        }

        return dummy->next;
    }
};

int main()
{
}