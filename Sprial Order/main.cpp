#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void changeDirection(int width, int height, int &pw, int &ph, int &left, int &top, int &right, int &bottom, int &time)
    {
        if (pw != 0)
        {
            if (pw > 0)
            {
                top += 1;
                time = height - bottom;
            }
            else
            {
                bottom += 1;
                time = height - top- bottom;
            }
            time = height - top- bottom;

            ph = pw;
            pw = 0;
        }
        else
        {
            if (ph > 0)
            {
                right += 1;
                time = width - left;
            }
            else
            {
                left += 1;
                time = width - right;
            }
                time = width - right -left;

            pw = ph * -1;
            ph = 0;
        }
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result = vector<int>();
        if (matrix.empty())
            return result;

        int m = 0;
        int n = 0;
        int pw = 1;
        int ph = 0;
        int left = 0;
        int top = 0;
        int right = 0;
        int bottom = 0;
        int width = matrix[0].size();
        int height = matrix.size();

        int time = width - 1;
        if (width == 1 && height == 1)
            return matrix[0];
        cout << width << "-" << height << endl;
        while (true)
        {
            if (time == 0)
            {
                changeDirection(width, height, pw, ph, left, top, right, bottom, time);
            }
            result.push_back(matrix[n][m]);
            cout << matrix[n][m] << "-" << n << "-" << m << "-" << time << endl;
            m = m + pw;
            n = n + ph;
            time = time - 1;

            if (result.size() == width * height)
                break;
        }

        return result;
    }
};

int main()
{
    Solution s = Solution();

    cin.get();
}