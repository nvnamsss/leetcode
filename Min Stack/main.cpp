#include <bits/stdc++.h>
using namespace std;

    class MinStack {
        stack<long> s;
        long minValue;
    public:
        MinStack() {
            minValue = -1;
        }
        
        void push(int val) {
            if (s.empty()) {
                minValue = val;
                s.push(val);
            } else if (val < minValue) {
                long v = val;
                s.push(2 * v - minValue);
                minValue = val;
            } else {
                s.push(val);
            }
        }
        
        void pop() {
            long t = s.top();
            if (t < minValue) {
                minValue = 2 * minValue - t;
            }
            s.pop();

        }
        
        int top() {
            long t = s.top();
            if (t < minValue) return minValue;
            return t;
        }
        
        int getMin() {
            return minValue;
        }
    };
