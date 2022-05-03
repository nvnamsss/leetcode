#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val, ListNode* next = NULL) {
        this->val = val;
        this->next = next;
    }
};

class MyHashSet {  
    vector<ListNode*> nodes;
    int hash(int key) {
        return key % collision;
    }
    int collision;
public:
    MyHashSet() {
        collision = 15;
        nodes = vector<ListNode*>(collision, new ListNode(0));
    }
    
    void add(int key) {
        if (contains(key)) {
            return;
        }
        int h = hash(key);

        ListNode* dummy = nodes[h];
        ListNode* node = new ListNode(key, dummy->next);
        dummy->next = node;
    }
    
    void remove(int key) {
        if (!contains(key)) {
            return;
        }
        int h = hash(key);
        ListNode* dummy = nodes[h];

        while (dummy->next && dummy->next->val != key) {
            dummy = dummy->next;
        }

        dummy->next = dummy->next->next;
    }
    
    bool contains(int key) {
        int h = hash(key);
        ListNode* dummy = nodes[h]->next;
        while (dummy) {
            if (dummy->val == key) {
                return true;
            }

            dummy = dummy->next;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
    MyHashSet mhs = MyHashSet();
    mhs.add(1);
    mhs.add(2);
    cout << mhs.contains(1) << endl;
    cout << mhs.contains(3) << endl;
    mhs.add(2);
    cout << mhs.contains(2) << endl;
    mhs.remove(2);
    cout << mhs.contains(2) << endl;
}