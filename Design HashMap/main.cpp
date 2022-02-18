/*
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 

Example 1:

Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
 

Constraints:

0 <= key, value <= 106
At most 104 calls will be made to put, get, and remove.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int value;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};
class MyHashMap
{
    int wise = 7;
    int size;
    vector<vector<Node *>> arr;
    int hash(int key)
    {
        return key % wise;
    }

public:
    MyHashMap()
    {
        size = 0;
        arr = vector<vector<Node*>>(wise, vector<Node*>());
    }

    void put(int key, int value)
    {
        int index = hash(key);
        for (int i = 0; i < arr[index].size(); i++)
        {
            if (arr[index][i]->key == key)
            {
                arr[index][i]->value = value;
                return;
            }
        }
        Node *node = new Node(key, value);
        arr[index].push_back(node);
        size++;
    }

    int get(int key)
    {
        int index = hash(key);
        for (int i = 0; i < arr[index].size(); i++)
        {
            if (arr[index][i]->key == key)
            {
                return arr[index][i]->value;
            }
        }

        return -1;
    }

    void remove(int key)
    {
        int index = hash(key);
        for (int i = 0; i < arr[index].size(); i++)
        {
            if (arr[index][i]->key == key)
            {
                arr[index][i] = arr[index][arr[index].size() - 1];
                arr[index].pop_back();
                return;
            }
        }
    }
};
    /**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(){
    MyHashMap hm;
    hm.put(1,1);
    hm.put(2,2);
    cout <<hm.get(1) << endl;
    cout << hm.get(3) << endl;
    hm.put(2,1);
    cout << hm.get(2) << endl;
    hm.remove(2);
    cout << hm.get(2) << endl;

}