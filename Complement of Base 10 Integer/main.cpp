#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 0;
        int i = 31;
        while (((n & 1) << i) == 0) {
            i--;
        } 

        while (i >= 0) {
            n ^= 1 << i;
            i--;
        }

        return n;
    }
};