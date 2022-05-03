#include <bits/stdc++.h>
using namespace std;

class Iterator
{
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator
{
    bool cached;
    int val;

public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        cached = false;
        val = 0;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        if (!cached)
        {
            val = Iterator::next();
            cached = true;
        }

        return val;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        if (cached)
        {
            cached = false;
            return val;
        }
        return Iterator::next();
    }

    bool hasNext() const
    {
        if (cached)
            return true;

        return Iterator::hasNext();
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    PeekingIterator pi = PeekingIterator(nums);
    cout << pi.next() << endl;
    cout << pi.peek() << endl;
    cout << pi.next() << endl;
    cout << pi.next() << endl;
    cout << pi.hasNext() << endl;
}