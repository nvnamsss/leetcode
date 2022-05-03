#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool palindrome(string s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) return false;

            l++;
            r--; 
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r]) {
                return palindrome(s, l, r - 1) || palindrome(s, l + 1, r);
            }
            l++;
            r--;
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << s.validPalindrome("aba") << endl;
    cout << s.validPalindrome("abca") << endl;
    cout << s.validPalindrome("abc") << endl;
    cout << s.validPalindrome("a") << endl;
    cout << s.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") << endl;
}