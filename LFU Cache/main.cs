/*
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

 

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[3,4], cnt(4)=2, cnt(3)=3
 

Constraints:

0 <= capacity, key, value <= 104
At most 105 calls will be made to get and put.
 

Follow up: Could you do both operations in O(1) time complexity?
*/
using System;
using System.Collections.Generic;


public class Quadnode<T>
{
    public T Value;
    public int Key;
    public int Counter;
    public Quadnode<T> left;
    public Quadnode<T> right;
    public Quadnode<T> up;
    public Quadnode<T> down;

    public Quadnode(T value, Quadnode<T> left = null, Quadnode<T> right = null, Quadnode<T> up = null, Quadnode<T> down = null)
    {
        Value = value;
        this.left = left;
        this.right = right;
        this.up = up;
        this.down = down;
    }

    public void SetVertical(Quadnode<T> up, Quadnode<T> down)
    {
        up.down = this;
        down.up = this;
    }

    public void SetHorizontal(Quadnode<T> left, Quadnode<T> right)
    {
        left.right = this;
        right.left = this;
    }

    public void RemoveVertical()
    {
        if (up != null) up.down = down;
        if (down != null) down.up = up;
        up = null;
        down = null;
    }

    public void RemoveHorizontal() {
        if (left != null) left.right = right;
        if (right != null) right.left = left;
        left = null;
        right = null;
    }
}

public class Trie<T>
{
    public T Value;
    public Trie<T> Next;
    public Trie<T> Previous;
    public Trie<T> Up;
    public Trie(T value, Trie<T> next = null, Trie<T> previous = null, Trie<T> up = null)
    {
        Value = value;
        Next = next;
        Previous = previous;
        Up = up;
    }
}

public class DoublyLinkedList<T>
{
    public T Value;
    public DoublyLinkedList<T> Previous;
    public DoublyLinkedList<T> Next;

    public DoublyLinkedList(T value, DoublyLinkedList<T> prev = null, DoublyLinkedList<T> next = null)
    {
        Value = value;
        Previous = prev;
        Next = next;
    }

    private void SetPrevious(DoublyLinkedList<T> previous)
    {
        Previous = previous;
        if (previous != null) previous.Next = this;
    }

    private void SetNext(DoublyLinkedList<T> next)
    {
        Next = next;
        if (next != null) next.Previous = this;
    }

    public void Set(DoublyLinkedList<T> prev, DoublyLinkedList<T> next)
    {
        SetPrevious(prev);
        SetNext(next);
    }

    public void Delete()
    {
        Previous?.SetNext(Next);
        Next?.SetPrevious(Previous);

        Previous = null;
        Next = null;
    }
}

public class Data<TKey, TValue>
{
    public TKey Key;
    public TValue Value;
    public int Counter;
    public Data()
    {

    }

    public Data(TKey key, TValue value)
    {
        Key = key;
        Value = value;
    }
}

public class Circular<T>
{
    public int Count;
    public DoublyLinkedList<T> first;

    public Circular(DoublyLinkedList<T> node)
    {
        first = node;
        first.Next = first;
        first.Previous = first;
        Count = 1;
    }

    public void Insert(DoublyLinkedList<T> node)
    {
        node.Set(first, first.Next);
        Count++;
    }

    public DoublyLinkedList<T> Pop()
    {
        DoublyLinkedList<T> f = first;
        f.Delete();
        Count--;
        return f;
    }

    public void Delete(DoublyLinkedList<T> node)
    {
        if (node == first)
        {
            Pop();
            return;
        }

        node.Delete();
        Count--;
    }
}


// 1 -> 1 -> 1 -> 2 -> 2 -> 3 -> 3 -> 4
// when an value is update, it will append to the last greater
// how should we call that? we have a node to storage the tier (counter)
// in each tier, contains others counter with the same value, 
// then the complexity is O(2) = O(1)
// the right node will point to greater counter, the left node will point to the equal counters
// when a node is updated, if update the counter, a cicurlar node will be created
public class LFUCache
{
    int capacity;

    Dictionary<int, Quadnode<int>> hash;
    Quadnode<int> dummy;
    public LFUCache(int capacity)
    {
        this.capacity = capacity;
        hash = new Dictionary<int, Quadnode<int>>(capacity);
        dummy = new Quadnode<int>(0);
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
            if (hash.Count == capacity)
            {
                DeleteFirst();
            }

            Quadnode<int> q = new Quadnode<int>(value);
            q.Key = key;
            hash.Add(key, q);
            Insert(q, dummy);
        }
        else
        {
            UpdateKey(key);
        }

        hash[key].Value = value;
    }

    private void Insert(Quadnode<int> q, Quadnode<int> after)
    {
        Quadnode<int> f = after.right;
        if (f == null)
        {
            q.SetHorizontal(after, f);
        }
        else
        {
            if (f.Counter == q.Counter)
            {
                q.left = f.left;
                q.right = f.right;
                q.SetVertical(f, f.up);
            }
            else
            {
                q.SetHorizontal(after, f);
            }
        }
    }

    private void UpdateKey(int key)
    {
        Quadnode<int> q = hash[key];
        q.Counter++;
        Insert(q, q.left.right);
    }

    private void DeleteFirst()
    {
        Quadnode<int> f = dummy.right;
        if (f.up != null) {
            f.up.SetHorizontal(f.left, f.right);
        } else {
            f.RemoveHorizontal();           
        }

        f.left = null;
        f.right =  null;
        f.up = null;
        f.down = null;
    }

}

