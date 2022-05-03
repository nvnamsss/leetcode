#include <bits/stdc++.h>
using namespace std;

class Logger {
    unordered_map<string, int> m;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (m.find(message) == m.end() || m[message] + 10 <= timestamp) {
            m[message] = timestamp;
            return true;
        }

        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */