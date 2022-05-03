#include <bits/stdc++.h>
using namespace std;

class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> values;
    int maxFreq;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        
        maxFreq = max(maxFreq, freq[val]);
        values[freq[val]].push(val);        
    }
    
    int pop() {
        int val = values[maxFreq].top();
        values[maxFreq].pop();
        freq[val]--;
        if (values[maxFreq].empty()) {
            maxFreq--;
        }

        return val;        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */