#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int i = 0;
        stack<string> d;
        while (i < path.size()) {
            string s = "";
            while (i < path.size() && path[i] != '/') {
                s += path[i];
                i++;
            }

            if (s == "..") {
                if (!d.empty()) {
                    d.pop();
                }
            } else if (s != "." && s != "") {
                d.push(s);
            }
            i++;
        }

        string ans = "";
        while (!d.empty()) {
            ans = "/" + d.top() + ans;
            d.pop();
        }

        return ans != "" ? ans : "/";
    }
};

int main() {
    Solution s;
    cout << s.simplifyPath("/home/") << endl;
    cout << s.simplifyPath("/../") << endl;
    cout << s.simplifyPath("/home//foo/") << endl;
}