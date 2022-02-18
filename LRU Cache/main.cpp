#include <bits/stdc++.h>
using namespace std;

struct DoublyLinkedlist
{
    DoublyLinkedlist *next;
    DoublyLinkedlist *prev;
    int key;
    int value;
    DoublyLinkedlist(int key, int value, DoublyLinkedlist *next = NULL, DoublyLinkedlist *prev = NULL)
    {
        this->key = key;
        this->value = value;
        this->next = next;
        this->prev = prev;
    }

    void SetNext(DoublyLinkedlist* next) {
        this->next = next;
        if (next) {
            next->prev = this;
        }
    }

    void SetPrevious(DoublyLinkedlist* prev) {
        this->prev = prev;
        if (prev) {
            prev->next = this;
        }
    }
};

class LRUCache
{
    unordered_map<int, DoublyLinkedlist *> map;
    DoublyLinkedlist *dummy;
    DoublyLinkedlist *last;
    int capacity;
    void update(int key)
    {
        DoublyLinkedlist *node = map[key];
        if (node == last)
        {
            return;
        }

        DoublyLinkedlist *prev = node->prev;
        prev->SetNext(node->next);

        last->SetNext(node);
        node->SetNext(NULL);

        last = node;
    }

public:
    LRUCache(int capacity)
    {
        dummy = new DoublyLinkedlist(0, 0);
        last = dummy;
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
        {
            return -1;
        }
        update(key);
        return map.find(key) != map.end() ? map[key]->value : -1;
    }

    void put(int key, int value)
    {
        if (map.find(key) == map.end())
        {
            if (map.size() == capacity)
            {
                DoublyLinkedlist *first = dummy->next;
                dummy->SetNext(first->next);
                if (last == first) {
                    last = dummy;
                }
                map.erase(first->key);
            }
            DoublyLinkedlist *node = new DoublyLinkedlist(key, value);
            last->SetNext(node);
            last = node;
            map.insert({key, node});
        }
        else
        {
            update(key);
            map[key]->value = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache* cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;
    cache->put(3, 3);

    cache = new LRUCache(3);
    cache->put(1,1);
    cache->put(2,2);
    cache->put(3,3);
    cache->put(4,4);
    cout << cache->get(4) << endl;
    cout << cache->get(3) << endl;
    cout << cache->get(2) << endl;
    cout << cache->get(1) << endl;
    cache->put(5,5);

    cache = new LRUCache(1);
    cache->put(1,1);
    cache->put(2,2);
}