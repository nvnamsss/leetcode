#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *cur = head;
        while (cur)
        {
            if (cur->child)
            {
                Node *next = cur->next;
                Node *f = flatten(cur->child);
                cur->next = f;
                f->prev = cur;
                while (f->next)
                {
                    f = f->next;
                }
                f->next = next;
                if (next) next->prev = f;
                cur->child = NULL;
                cur = next;
            }
            else
            {
                cur = cur->next;
            }
        }
        cur = head;
        while (cur->next)
        {
            cout << cur->next->prev->val << " - " << cur->next->val << endl;
            cur = cur->next;
        }
        return head;
    }
};