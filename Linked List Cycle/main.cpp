/*
This problem is duplicated with Cycle Linked List
*/

#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode *hare = head->next;
        ListNode *turtoise = head;

        while (hare != turtoise)
        {   
            if (hare == NULL || hare->next == NULL) return false;
            hare = hare->next->next;
            turtoise = turtoise->next;
        }

        return true;

    }
};