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
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* back = dummy;
        while (back->next) {
            ListNode* front = dummy;
            ListNode* next = back->next;
            while (front->next->val < next->val) {
                front = front->next;
            }
            if (front->next != next) {
                back->next = back->next->next;
                next->next = front->next;
                front->next = next;
            } else {
                back = back->next;
            }
        }

        return dummy->next;
    }
};

ListNode* create(vector<int>& v) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int i = 0; i < v.size(); i++)
    {
        cur->next = new ListNode(v[i]);
        cur = cur->next;
    }
    
    return dummy->next;
}

int main() {
    Solution s;
    vector<int> values = {4,2,1,3};
    ListNode* head = create(values);
    s.insertionSortList(head);
}