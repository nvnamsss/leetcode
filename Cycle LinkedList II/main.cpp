#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    int index;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) 
    {
                
    }
};

class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
        ListNode *hare = head->next;
        ListNode *turtoise = head;

        while (hare != turtoise)
        {   
            if (hare == NULL || hare->next == NULL) return NULL;
            hare = hare->next->next;
            turtoise = turtoise->next;
        }

        hare = turtoise;
        turtoise = head;

        while (hare != turtoise)
        {
            hare = hare->next;
            turtoise = turtoise->next;
        }

        return turtoise;
    }
};

int main()
{
    Solution s = Solution();

    cin.get();
}