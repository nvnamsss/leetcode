#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int l = 1;
        int r = 32;
        while (l < r) {
            int bitl = (n >> l) & 1;
            int bitr = (n >> r) & 1;

            //set bit left to bit right
            int maskl = 1 << l;
            int maskr = 1 << r;
            n = (n & ~maskl) | ((bitr << l) & maskl);
            //set bit right to bit left
            n = (n & ~maskr) | ((bitl << r) & maskr);

            l++;
            r--;
        }

        return n;
    }
};

int main(){
}