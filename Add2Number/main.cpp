#include <iostream>
#include <cmath>
using namespace std;
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l = l1;
        ListNode *lr = new ListNode(0);
        ListNode *lrf = lr;
        int r = 0;
        while (l != NULL)
        {
            if (l1 != NULL)
            {
                lr->val += l1->val;
            }
            
            if (l2 != NULL)
            {
                lr->val += l2->val;
            }

            r = lr->val / 10;
            lr->val = lr->val % 10;
            
            cout << lr->val;
            if (l->next == NULL && l2 != NULL && l2->next != NULL) l = l2;

            if (l != NULL && l->next != NULL)
            {
                if (l1 != NULL) l1 = l1->next;
                if (l2 != NULL) l2 = l2->next;
                lr->next = new ListNode(r);
                lr = lr->next;
            }
            else //done
            {
                if (r > 0)
                {
                    lr->next = new ListNode(r);
                }
            }

            l = l->next;    
        }

        return lrf;
    }
};

int main()
{
    ListNode *l1 = new ListNode(0);
    // l1->next = new ListNode(4);
    ListNode *l2 = new ListNode(7);
    l2->next = new ListNode(3);
    Solution s = Solution();
    ListNode * r = s.addTwoNumbers(l1, l2);
    cout << endl;
    while (r != NULL)
    {
        cout << r->val;
        r = r->next;
    }
        cin.get();
}