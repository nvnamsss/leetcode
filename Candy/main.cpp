/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.



Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.


Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int getRating(vector<int> &ratings, int i)
    {
        if (i < 0 || i >= ratings.size())
        {
            return INT32_MAX;
        }
        return ratings[i];
    }

    int getCandy(vector<int> &candies, int i)
    {
        if (i < 0 || i >= candies.size())
        {
            return 0;
        }
        return candies[i];
    }

public:
    int candy(vector<int> &ratings)
    {
        vector<int> candies = vector<int>(ratings.size());
        int ans = 0;

        for (int i = 0; i < ratings.size(); ++i)
        {
            int m = getRating(ratings, i);
            int l = getRating(ratings, i - 1);
            int r = getRating(ratings, i + 1);

            if (l >= m && m <= r)
            {
                candies[i] = 1;
            }
        }


        for (int i = 0; i < ratings.size(); ++i)
        {
            int m = getRating(ratings, i);
            int l = getRating(ratings, i - 1);
            int r = getRating(ratings, i + 1);

            if (m > l || m > r)
            {
                int cl = 0;
                int cr = 0;
                if (m > l) {
                    cl = getCandy(candies, i - 1) + 1;
                }

                if (m > r) {
                    cr = getCandy(candies, i + 1) + 1;
                }

                candies[i] = max(cl, cr);
            }
        }

        for (int i = ratings.size() - 1; i >= 0; --i)
        {
            int m = getRating(ratings, i);
            int l = getRating(ratings, i - 1);
            int r = getRating(ratings, i + 1);

            if (m > l || m > r)
            {
                int cl = 0;
                int cr = 0;
                if (m > l) {
                    cl = getCandy(candies, i - 1) + 1;
                }

                if (m > r) {
                    cr = getCandy(candies, i + 1) + 1;
                }

                candies[i] = max(cl, cr);
            }
        }

        for (int i = 0; i < candies.size(); ++i)
        {
            ans += candies[i];
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> ratings = {1, 0, 2};
    cout << s.candy(ratings) << endl;

    ratings = {1, 2, 2};
    cout << s.candy(ratings) << endl;

    ratings = {1,0,2,3,4,5,5,1,23,5,7,6,2,7,8,9};
    cout << s.candy(ratings) << endl;
}