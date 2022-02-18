/*
Design the CombinationIterator class:

CombinationIterator(string characters, int combinationLength) Initializes the object with a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
next() Returns the next combination of length combinationLength in lexicographical order.
hasNext() Returns true if and only if there exists a next combination.
 

Example 1:

Input
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
Output
[null, "ab", true, "ac", true, "bc", false]

Explanation
CombinationIterator itr = new CombinationIterator("abc", 2);
itr.next();    // return "ab"
itr.hasNext(); // return True
itr.next();    // return "ac"
itr.hasNext(); // return True
itr.next();    // return "bc"
itr.hasNext(); // return False
 

Constraints:

1 <= combinationLength <= characters.length <= 15
All the characters of characters are unique.
At most 104 calls will be made to next and hasNext.
It's guaranteed that all calls of the function next are valid.
*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    string val;
    Node *next;
    Node(string val, Node *next = NULL)
    {
        this->val = val;
        this->next = next;
    }
};

class CombinationIterator
{
    Node *dummy;
    Node *current;
    string characters;

    int bitcount(int n)
    {
        int count = 0;
        while (n)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    void backtrack(string characters, string s, int start, int length) {
        if (start == characters.size() + 1) {
            return;
        }

        if (s.size() == length) {
            current->next = new Node(s);
            current = current->next;
            return;
        }

        for (int i = start; i < characters.size(); i++)
        {
            backtrack(characters, s + characters[i], i + 1, length);
        }
    }
public:
    CombinationIterator(string characters, int combinationLength)
    {
        this->characters = characters;
        int total = 1 << characters.size();
        dummy = new Node("");
        current = dummy;
        backtrack(characters, "", 0, combinationLength);
        // for (int mask = 1; mask < total; mask++)
        // {
        //     if (bitcount(mask) != combinationLength)
        //     {
        //         continue;
        //     }
        //     string s = "";
        //     for (int i = 0; i < characters.size(); i++)
        //     {
        //         if (mask & (1 << i))
        //         {
        //             s += characters[i];
        //         }
        //     }

        //     cur->next = new Node(s);
        //     cur = cur->next;
        // }

        current = dummy->next;
    }

    string next()
    {
        string val = current->val;
        current = current->next;
        return val;
    }

    bool hasNext()
    {
        return current;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    CombinationIterator* ci = new CombinationIterator("bvwz", 2);
}