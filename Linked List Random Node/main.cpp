#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    int k = 1;
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        ListNode* cur = head;
        int chosen = 0;
        int scope = 1;
        
        while (cur) {
            int r = rand() % scope;
            if (r < 1) {
                chosen = cur->val;
            }
            cur = cur->next;
            scope++;
        }
        return chosen;
    }
};

ListNode* create(int n) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    for (int i = 0; i < n; i++)
    {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    
    return dummy->next;
}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main() {
    ListNode* node = create(3);
    Solution s = Solution(node);
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
}