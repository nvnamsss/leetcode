#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* next;
    Node(int val, Node* next = NULL) {
        this->val = val;
        this->next = next;
    }
};
class stack {
    Node* head;
    int count;
    stack() {
        head = new Node(0);
        count = 0;
    }

    void push(int v) {
        Node* n = new Node(v, head->next); 
        head->next = n;
        count++;
    }

    int pop() {
        if (count == 0) return -1;
        Node* n = head->next;
        head->next = head->next->next;
        count--;
        return n->val;
    }

    vector<int> array() {
        vector<int> ans = vector<int>(count);
        Node* cur = head->next;
        while (cur )
        return ans;
    }
};