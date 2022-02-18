#include <bits/stdc++.h>
using namespace std;

class CuckooHashing {
    vector<int> t1;
    vector<int> t2;

    int h1(int x) {
        return x % 11;
    }
    int h2(int x) {
        return (x % 6) % 11;
    }
};