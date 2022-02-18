/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int val, Node *next = NULL)
    {
        this->val = val;
        this->next = next;
    }
};
class MyLinkedList
{
    int size;
    Node *dummy;
    Node *last;

public:
    MyLinkedList()
    {
        size = 0;
        dummy = new Node(0);
        last = dummy;
    }

    int get(int index)
    {
        Node *cur = dummy->next;
        int i = 0;
                cout <<cur->val << endl;

        while (i < index && cur)
        {
            cur = cur->next;
            i++;
        }

        return cur ? cur->val : -1;
    }

    void addAtHead(int val)
    {
        Node *node = new Node(val, dummy->next);
        dummy->next = node;
        size++;
        if (size == 1)
        {
            last = node;
        }
    }

    void addAtTail(int val)
    {
        Node *node = new Node(val);
        last->next = node;
        last = node;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size) {
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* cur = dummy;
        int i = 0;
        while (i < index && cur)
        {
            cur = cur->next;
            i++;
        }

        Node* node = new Node(val, cur->next);
        cur->next = node;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size) {
            return;
        }
        Node* cur = dummy;
        int i = 0;
        while (i < index && cur)
        {
            cur = cur->next;
            i++;
        }

        cur->next = cur->next->next;
        if (!cur->next) {
            last = cur;
        }
        size--;
    }
};

int main() {
    MyLinkedList m;
    m.addAtHead(1);
    m.addAtTail(3);
    m.addAtIndex(1,2);
    cout << m.get(1) << endl;
    m.deleteAtIndex(2);
    cout << m.get(1) << endl;

    MyLinkedList m2;
    m2.addAtHead(9);
    m2.get(1);
    m2.addAtIndex(1,1);
    m2.addAtIndex(1,7);
    m2.deleteAtIndex(1);
    m2.addAtHead(7);
    m2.deleteAtIndex(1);
    m2.addAtHead(4);
    m2.deleteAtIndex(1);
    m2.addAtIndex(1, 4);
    m2.addAtHead(2);
    m2.deleteAtIndex(5);

}