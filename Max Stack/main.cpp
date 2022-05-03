/*
Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

MaxStack() Initializes the stack object.
void push(int x) Pushes element x onto the stack.
int pop() Removes the element on top of the stack and returns it.
int top() Gets the element on the top of the stack without removing it.
int peekMax() Retrieves the maximum element in the stack without removing it.
int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the top-most one.
 

Example 1:

Input
["MaxStack", "push", "push", "push", "top", "popMax", "top", "peekMax", "pop", "top"]
[[], [5], [1], [5], [], [], [], [], [], []]
Output
[null, null, null, null, 5, 5, 1, 5, 1, 5]

Explanation
MaxStack stk = new MaxStack();
stk.push(5);   // [5] the top of the stack and the maximum number is 5.
stk.push(1);   // [5, 1] the top of the stack is 1, but the maximum is 5.
stk.push(5);   // [5, 1, 5] the top of the stack is 5, which is also the maximum, because it is the top most one.
stk.top();     // return 5, [5, 1, 5] the stack did not change.
stk.popMax();  // return 5, [5, 1] the stack is changed now, and the top is different from the max.
stk.top();     // return 1, [5, 1] the stack did not change.
stk.peekMax(); // return 5, [5, 1] the stack did not change.
stk.pop();     // return 1, [5] the top of the stack and the max element is now 5.
stk.top();     // return 5, [5] the stack did not change.
 

Constraints:

-107 <= x <= 107
At most 104 calls will be made to push, pop, top, peekMax, and popMax.
There will be at least one element in the stack when pop, top, peekMax, or popMax is called.
 

Follow up: Could you come up with a solution that supports O(1) for each top call and O(logn) for each other call? 
*/

#include <bits/stdc++.h>
using namespace std;

class MaxStack
{
    struct DoublyLinkedList
    {
        int val;
        int maxVal;
        DoublyLinkedList *next;
        DoublyLinkedList *prev;
        DoublyLinkedList(int val)
        {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }

        void link(DoublyLinkedList *next = NULL, DoublyLinkedList *prev = NULL) {
            this->next = next;
            this->prev = prev;
            next->prev = this;
            prev->next = this;
        }
        void unlink()
        {
            prev->next = next;
            next->prev = prev;
            prev = NULL;
            next = NULL;
        }
    };
    DoublyLinkedList *dummy;
    map<int, vector<DoublyLinkedList *>> m;
    int maxVal;

public:
    MaxStack()
    {
        dummy = new DoublyLinkedList(0);
        dummy->link(dummy, dummy);
        maxVal = 0;
    }

    void push(int x)
    {
        DoublyLinkedList *node = new DoublyLinkedList(x);
        node->link(dummy->next, dummy);    
        maxVal = max(maxVal, x);
        node->maxVal = maxVal;
        if (m.find(node->val) == m.end())
        {
            m.insert({node->val, {}});
        }
        m[node->val].push_back(node);
    }

    int pop()
    {
        int val = dummy->next->val;
        dummy->next->unlink();
        m[val].pop_back();
        if (m[val].size() == 0)
        {
            m.erase(val);
        }
        return val;
    }

    int top()
    {
        return dummy->next->val;
    }

    int peekMax()
    {
        return (--m.end())->first;
    }
    int popMax()
    {
        auto it = m.end();
        it--;
        DoublyLinkedList *node = it->second[it->second.size() - 1];
        it->second.pop_back();
        node->unlink();

        if (it->second.size() == 0)
        {
            m.erase(node->val);
        }
        return node->val;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

int main()
{
    MaxStack s;
    s.push(5);
    s.push(1);
    s.push(5);
    cout << s.top() << endl;
    cout << s.popMax() << endl;
    cout << s.top() << endl;
    cout << s.peekMax() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;

    s = MaxStack();
    s.push(5);
    s.push(1);
    s.popMax();
    s.peekMax();
}