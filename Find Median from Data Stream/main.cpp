#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
    map<int, int> map;
    int total;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
        total = 0;
    }

    void addNum(int num)
    {
        total++;
        if (map.find(num) == map.end())
        {
            map.insert(pair<int, int>(num, 0));
        }
        map[num]++;
    }

    double findMedian()
    {
        int half = total / 2;
        int ratio = 0;
        for (auto const &pair : map)
        {
            if (ratio >= half) break;
            ratio += pair.second;
        }

        if (total % 2 == 1) {
            
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */