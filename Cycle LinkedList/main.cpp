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
    bool hasCycle(ListNode *head) {
        ListNode *hare = head->next;
        ListNode *turtoise = head;

        while (hare != turtoise)
        {   
            if (hare == NULL || turtoise == NULL) return false;
            hare = hare->next->next;
            turtoise = turtoise->next;
        }

        return true;
    }
};

int main()
{
    Solution s = Solution();
    
    cin.get();
}