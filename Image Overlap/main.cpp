/*
You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.

Return the largest possible overlap.



Example 1:


Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: We translate img1 to right by 1 unit and down by 1 unit.

The number of positions that have a 1 in both images is 3 (shown in red).

Example 2:

Input: img1 = [[1]], img2 = [[1]]
Output: 1
Example 3:

Input: img1 = [[0]], img2 = [[0]]
Output: 0


Constraints:

n == img1.length == img1[i].length
n == img2.length == img2[i].length
1 <= n <= 30
img1[i][j] is either 0 or 1.
img2[i][j] is either 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;



struct point
{
    int x;
    int y;

    point()
    {
    }

    point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    bool operator==(const point &other) const
    {
        return this->x == other.x && this->y == other.y;
    }
};

template <>
struct hash<point>
{
    size_t operator()(const point &p) const
    {
        return hash<int>()(p.x) ^ hash<int>()(p.y);
    }
};

class Solution
{
    vector<point> filter(vector<vector<int>> &img1) {
        vector<point> ans;
        for (int i = 0; i < img1.size(); i++)
        {
            for (int j = 0; j < img1.size(); j++)
            {
                if (img1[i][j]) {
                    ans.push_back(point(i, j));
                } 
            }
            
        }
        return ans;
    }
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        unordered_map<point, int> m;
        int n = img1.size();
        vector<point> a = filter(img1);     
        vector<point> b = filter(img2); 
        int ans = 0;    

        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                int dx = b[j].x - a[i].x;
                int dy = b[j].y - a[i].y;
                point p = point(dx, dy);
                m[p]++;
                ans = max(ans, m[p]);
            }
            
        }
        return ans;
    }
};