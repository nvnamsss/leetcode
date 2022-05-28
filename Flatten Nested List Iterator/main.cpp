#include <bits/stdc++.h>
using namespace std;
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class nestedInteger : public NestedInteger {
    int val = 0;
    bool integer;
    vector<NestedInteger> list;
    public:
    nestedInteger(int val) {
        integer = true;
        this->val = val;
    }

    nestedInteger(vector<NestedInteger>& list) {
        integer = false;
        this->list = list;
    }

    bool isInteger() {
        
        return this->integer;
    }

    int getInteger() {
        return val;
    }

    vector<NestedInteger>& getList() {
        return list;
    }
};

class NestedIterator {
    vector<NestedIterator> ni;
    int count = 0;
    int cur = 0;
    int val = 0;
    bool isInteger = false;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        cur = 0;
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger()) {
                NestedIterator v = NestedIterator(nestedList[i].getInteger());
                ni.push_back(v);
            } else {
                vector<NestedInteger> list = nestedList[i].getList();
                NestedIterator v = NestedIterator(list);

                if (v.count > 0) {
                    ni.push_back(v);
                }
            }
        }
        count = ni.size();

    }

    NestedIterator(int val) {
        this->isInteger = true;
        this->val = val;
    }

    int next() {
        if (isInteger) {
            return val;
        }

        int v = ni[cur].next();
        if (!ni[cur].hasNext()) {
            cur++;
        }
        
        return v;
    }
    
    bool hasNext() {
        return cur < count;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    vector<NestedInteger> input;
    nestedInteger i1 = nestedInteger(1);
    input.push_back(i1);

    NestedIterator ni = NestedIterator(input);
    while (ni.hasNext()) {
        cout << ni.next();
    }
}