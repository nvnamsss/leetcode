/*
You are given the head of a linked list.

The nodes in the linked list are sequentially assigned to non-empty groups whose lengths form the sequence of the natural numbers (1, 2, 3, 4, ...). The length of a group is the number of nodes assigned to it. In other words,

The 1st node is assigned to the first group.
The 2nd and the 3rd nodes are assigned to the second group.
The 4th, 5th, and 6th nodes are assigned to the third group, and so on.
Note that the length of the last group may be less than or equal to 1 + the length of the second to last group.

Reverse the nodes in each group with an even length, and return the head of the modified linked list.

 

Example 1:


Input: head = [5,2,6,3,9,1,7,3,8,4]
Output: [5,6,2,3,9,1,4,8,3,7]
Explanation:
- The length of the first group is 1, which is odd, hence no reversal occurrs.
- The length of the second group is 2, which is even, hence the nodes are reversed.
- The length of the third group is 3, which is odd, hence no reversal occurrs.
- The length of the last group is 4, which is even, hence the nodes are reversed.
Example 2:


Input: head = [1,1,0,6]
Output: [1,0,1,6]
Explanation:
- The length of the first group is 1. No reversal occurrs.
- The length of the second group is 2. The nodes are reversed.
- The length of the last group is 1. No reversal occurrs.
Example 3:


Input: head = [2,1]
Output: [2,1]
Explanation:
- The length of the first group is 1. No reversal occurrs.
- The length of the last group is 1. No reversal occurrs.
Example 4:

Input: head = [8]
Output: [8]
Explanation: There is only one group whose length is 1. No reversal occurrs.
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 105


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
    void reverse(ListNode* dummy, int k) {
        ListNode* prev = dummy;
        ListNode* cur = dummy->next;
        for (int i = 0; i < k; i++)
        {
            ListNode* n2 = cur->next;
            cur->next = n2->next;
            n2->next = cur;
            prev->next = n2;

            prev = n2;
        }
        
        if (k > 1) {
            reverse(dummy, k -1);
        }
    }  

public:
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        ListNode* dummy = new ListNode(0, head);
        int group = 1;
        ListNode* turtoise = dummy;
        ListNode* hare = dummy;
        while (turtoise) {
            int length = 0;
            for (int i = 0; i < group && hare->next; i++)
            {
                hare = hare->next;
                length++;
            }
            
            if (length % 2 == 0) {
                hare = turtoise->next;
                reverse(turtoise, length - 1);
            }

            turtoise = hare;
            group++;
        }

        return dummy->next;
    }
};

ListNode* init(vector<int> arr) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int i = 0; i < arr.size(); i++)
    {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return dummy->next;
}

void log(ListNode* head) {
    ListNode* cur = head;
    while(cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
int main() {
    Solution s;
    ListNode* head = init({5,2,6,3,9,1,7,3,8,4});
    ListNode* rs = s.reverseEvenLengthGroups(head);
    log(rs);
    head = init({0,4,2,1,3});
    rs = s.reverseEvenLengthGroups(head);
    log(rs);

}