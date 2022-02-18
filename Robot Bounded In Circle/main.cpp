#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int rotation = 180;
        int transition = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < instructions.size(); i++)
        {
            if (rotation < 0) {
                rotation += 360;
            }
            
            rotation = rotation % 360;
            if (instructions[i] == 'L') {
                rotation -= 90;
            } else if (instructions[i] == 'R') {
                rotation += 90;
            } else {
                if (rotation == 180) {
                    y++;
                } else if (rotation == 90) {
                    x--;
                } else if (rotation == 0) {
                    y--;
                } else {
                    x++;
                }
            }
        }
        
        return rotation != 0 || (x == 0 && y == 0);
    }
};