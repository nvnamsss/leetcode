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
        if (up != null) up.down = this;
        if (down != null) down.up = this;
        this.up = up;
        this.down = down;
    }

    public void SetHorizontal(Quadnode<T> left, Quadnode<T> right)
    {
        if (left != null) left.right = this;
        if (right != null) right.left = this;
        this.left = left;
        this.right = right;
    }

    public void RemoveVertical()
    {
        if (up != null) up.down = down;
        if (down != null) down.up = up;
        up = null;
        down = null;
    }

    public void RemoveHorizontal()
    {
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

public class DoublyNode<T>
{
    public T Value;
    public int Key;
    public int Frequency;
    public DoublyNode<T> Previous;
    public DoublyNode<T> Next;

    public DoublyNode() {
    }
    
    public DoublyNode(T value, DoublyNode<T> prev = null, DoublyNode<T> next = null)
    {
        Value = value;
        Previous = prev;
        Next = next;
    }

    private void SetPrevious(DoublyNode<T> previous)
    {
        Previous = previous;
        if (previous != null) previous.Next = this;
    }

    private void SetNext(DoublyNode<T> next)
    {
        Next = next;
        if (next != null) next.Previous = this;
    }

    public void Set(DoublyNode<T> prev, DoublyNode<T> next)
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
    public DoublyNode<T> first;

    public Circular(DoublyNode<T> node)
    {
        first = node;
        first.Next = first;
        first.Previous = first;
        Count = 1;
    }

    public void Insert(DoublyNode<T> node)
    {
        node.Set(first, first.Next);
        Count++;
    }

    public DoublyNode<T> Pop()
    {
        DoublyNode<T> f = first;
        f.Delete();
        Count--;
        return f;
    }

    public void Delete(DoublyNode<T> node)
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


public class DoublyLinkedList<T>
{
    private DoublyNode<T> head;
    private DoublyNode<T> tail;

    public DoublyLinkedList()
    {
        head = new DoublyNode<T>();
        tail = new DoublyNode<T>();
        head.Next = tail;
        tail.Previous = head;
    }

    public void Add(DoublyNode<T> node)
    {
        DoublyNode<T> prev = head;
        DoublyNode<T> next = head.Next;
        
        prev.Next = node;
        next.Previous = node;
        node.Previous = prev;
        node.Next = next;
    }

    public void Remove(DoublyNode<T> node)
    {
        DoublyNode<T> prev = node.Previous;
        DoublyNode<T> next = node.Next;

        prev.Next = next;
        next.Previous = prev;
        node.Previous = null;
        node.Next = null;
    }

    public DoublyNode<T> RemoveFirst()
    {
        DoublyNode<T> f = tail.Previous;
        Remove(f);
        return f;
    }

    public bool Empty()
    {
        return head.Next == tail;
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

    Dictionary<int, DoublyNode<int>> cache;
    Dictionary<int, DoublyLinkedList<int>> frequencies;

    int minFrequency;
    public LFUCache(int capacity)
    {
        this.capacity = capacity;
        cache = new Dictionary<int, DoublyNode<int>>(capacity);
        frequencies = new Dictionary<int, DoublyLinkedList<int>>(capacity);

    }

    public int Get(int key)
    {
        if (!cache.ContainsKey(key)) return -1;

        UpdateKey(key);

        return cache[key].Value;
    }

    public void Put(int key, int value)
    {
        if (capacity == 0) return;
        
        if (!cache.ContainsKey(key))
        {
            if (cache.Count == capacity)
            {
                DoublyNode<int> f = frequencies[minFrequency].RemoveFirst();
                cache.Remove(f.Key);
            }

            DoublyNode<int> d = new DoublyNode<int>(value);
            d.Key = key;
            d.Frequency =1;
            cache.Add(key, d);

            if (!frequencies.ContainsKey(1))
            {
                frequencies.Add(1, new DoublyLinkedList<int>());
                minFrequency = 1;
            }

            frequencies[1].Add(d);
        }
        else
        {
            UpdateKey(key);
        }

        cache[key].Value = value;
    }

    /*
        move the node to the next, 
    */

    private void UpdateKey(int key)
    {
        DoublyNode<int> d = cache[key];
        frequencies[d.Frequency].Remove(d);
        if (frequencies[d.Frequency].Empty())
        {
            frequencies.Remove(d.Frequency);
        }

        d.Frequency++;
        if (!frequencies.ContainsKey(d.Frequency))
        {
            frequencies.Add(d.Frequency, new DoublyLinkedList<int>());
        }

        frequencies[d.Frequency].Add(d);

        if (!frequencies.ContainsKey(minFrequency) || frequencies[minFrequency].Empty()) {
            minFrequency++;
        }
    }

}

