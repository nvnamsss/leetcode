#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        6 4 1 - 2 <=> [2][1][2][2] <=> [2][0] 4 5 2 6 5 8 1 - 1 <=> [1][1][2][1] <=> [1][0] 8 2 1 - 0 <=> [0][1][2][0] <=> [0][0] 1 2 3 9 6 1 9 4 1 9 4 1 4 5 6 4 5 2 6 5 2 8 5 2 7 8 9 7 8 3 7 8 3 7 6 3
            /*row n will be column length - a
        swap without allocate
        we sure that matrix is n * n size
        */
            int length = matrix.size();
        //counter clockwise
        for (int loop = 0; loop < length; loop++)
        {
            for (int loop2 = 0; loop2 >= 0; loop2--)
            {
                int temp = matrix[loop][loop2];
                matrix[loop][loop2] = matrix[loop2][length - loop - 1];
                matrix[loop2][length - loop - 1] = temp;
            }
        }

        //clockwise
        for (int loop = 0; loop < length; loop++)
        {
            for (int loop2 = loop; loop2 < length; loop2++)
            {
                int temp = matrix[loop][loop2];
                matrix[loop][loop2] = matrix[loop2][loop];
                matrix[loop2][loop] = temp;
            }
        }

        for (int loop = 0; loop < length; loop++)
        {
            for (int loop2 = 0; loop2 < length / 2; loop2++)
            {
                int temp = matrix[loop][loop2];
                matrix[loop][loop2] = matrix[loop][length - loop2 - 1];
                matrix[loop][length - loop2 - 1] = temp;
            }
        }
    }
};

int main()
{
    Solution s = Solution();
    cin.get();
}