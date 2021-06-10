#include <queue>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool compare(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> q = priority_queue<int>();
        sort(courses.begin(), courses.end(), compare);
        int time = 0;
        for (int loop = 0; loop < courses.size(); loop++)
        {   
            vector<int> c = courses[loop];
            if (time + c[0] <= c[1]) {
                time = time + c[0];
                q.push(c[0]); 
            } else {
                if (!q.empty() && q.top() > c[0]) {
                    int r = q.top();
                    q.pop();
                    time = time + c[0] - r;
                    q.push(c[0]);
                }
            }
            /* code */
        }
        
        return q.size();
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> courses {
        vector<int>{1, 2},
    };

    int rs = s.scheduleCourse(courses);
    cout << "Result: " << rs << " - " << "Expect: 1" << endl;
 
    return 0;
}