/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
Follow up:
Could you do get and put in O(1) time complexity?

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 3000
0 <= value <= 104
At most 3 * 104 calls will be made to get and put.
*/

using System;
using System.Collections;
using System.Collections.Generic;

public class DoublyLinkedList<T>
{
    public T Value;
    public T Key;
    public DoublyLinkedList<T> Left;
    public DoublyLinkedList<T> Right;
    public DoublyLinkedList(T value, DoublyLinkedList<T> left = null, DoublyLinkedList<T> right = null)
    {
        this.Left = left;
        this.Right = right;
        this.Value = value;
    }

    public void SetLeft(DoublyLinkedList<T> left)
    {
        Left = left;
        if (Left != null) Left.Right = this;
    }

    public void SetRight(DoublyLinkedList<T> right)
    {
        Right = right;
        if (Right != null) Right.Left = this;
    }
}

public class LRUCache
{
    int capaciy;
    Dictionary<int, DoublyLinkedList<int>> hash;
    DoublyLinkedList<int> last;
    public LRUCache(int capacity)
    {
        this.capaciy = capacity;
        hash = new Dictionary<int, DoublyLinkedList<int>>();
    }

    public int Get(int key)
    {
        if (!hash.ContainsKey(key)) return -1;
        UpdateKey(key);

        return hash[key].Value;
    }

    public void Put(int key, int value)
    {
        if (!hash.ContainsKey(key))
        {
            if (hash.Count >= capaciy)
            {
                hash.Remove(last.Right.Key);
                last.SetRight(last.Right.Right);
            }

            hash.Add(key, new DoublyLinkedList<int>(value));

            if (last == null)
            {
                hash[key].Left = hash[key];
                hash[key].Right = hash[key];
            }
            else
            {
                hash[key].SetRight(last.Right);
                hash[key].SetLeft(last);
            }
            last = hash[key];
            hash[key].Key = key;
        }
        else
        {
            UpdateKey(key);
            hash[key].Value = value;
        }
    }
    // 2 -> 3 => 2-> => 2 -> 3
    private void UpdateKey(int key)
    {
        if (hash[key] == last) return;
        hash[key].Left.SetRight(hash[key].Right);

        hash[key].SetRight(last.Right);
        hash[key].SetLeft(last);

        last = hash[key];
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */