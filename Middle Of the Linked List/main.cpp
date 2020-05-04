#include <iostream>

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *turtoise = head;
        ListNode *hare = head;

        while (hare != NULL)
        {
            hare = hare->next;

            if (hare == NULL) break;
            hare = hare->next;
            turtoise = turtoise->next;
        }

        return turtoise;
    }
};