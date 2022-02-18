/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

Constraints:

1 <= k <= points.length <= 104
-104 < xi, yi < 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int distance(vector<int> point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    int partition(vector<vector<int>>& points, int left, int right, int pivot) {
        int pivotValue = distance(points[pivot]);
        swap(points[pivot], points[right]);
        int storeIndex = left;
        for (int i = left; i < right; i++)
        {
            if (distance(points[i]) < pivotValue) {
                swap(points[i], points[storeIndex]);
                storeIndex++;
            }
        }
        swap(points[right], points[storeIndex]);
        return storeIndex;
    }

    void quickselect(vector<vector<int>>& points, int left, int right, int k) {
        while (left < right) {
            int pivot = left + (right - left) / 2;
            pivot = partition(points, left, right, pivot);
            if (pivot == k) {
                return;
            } else if (pivot < k){
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        quickselect(points, 0, points.size() - 1, k);
        for (int i = 0; i < k; i++)
        {
            ans.push_back(points[i]);
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    s.kClosest(points, 2);
    points = {{3,3}};
    s.kClosest(points, 1);

    points = {{1,3},{-2,2},{2,-2}};
    s.kClosest(points, 2);
}