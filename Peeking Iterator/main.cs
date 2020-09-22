/*
Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

Example:

Assume that the iterator is initialized to the beginning of the list: [1,2,3].

Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2. 
You call next() the final time and it returns 3, the last element. 
Calling hasNext() after that should return false.
Follow up: How would you extend your design to be generic and work with all types, not just integer?
*/
using System;
using System.Collections.Generic;

class PeekingIterator {
    private List<int> l;
    private IEnumerator<int> ie;
    private int at;
    private int Count;
    
    // iterators refers to the first element of the array.
    public PeekingIterator(IEnumerator<int> iterator) {
        // initialize any member here.
        ie = iterator;
        ie.Reset();

        Count = 1;
        l.Add(ie.Current);

        while (ie.MoveNext())
        {
            l.Add(ie.Current);
            Count++;
        }

        ie.Reset();
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    public int Peek() {
        if (at + 1 < Count) return l[at + 1];
        return -1;
    }
    
    // Returns the next element in the iteration and advances the iterator.
    public int Next() {
        if (at < Count)
        {
            at++;
            return l[at];
        }
        return -1;
    }
    
    // Returns false if the iterator is refering to the end of the array of true otherwise.
    public bool HasNext() {
        return at < Count;
    }
}