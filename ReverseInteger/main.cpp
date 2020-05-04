#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        int count = 0;
        int r = 0;
        int tmp = x;
        int limit = x < 0 ? INT_MIN : INT_MAX;
        if (x < INT_MIN || x > INT_MAX) return 0;

        while (tmp != 0)
        {
            if (r >= 214748365 || r <= -214748365)
            {
                return 0;
            }

            r = r * 10 + tmp % 10;
            tmp = tmp / 10;
        }

        return r;
    }
};

int main()
{
    Solution s = Solution();
    int t1 = 123;
    int t2 = -123;
    int t3 = 120;
    int t4 = 0;
    int t5 = 0;

    cout << s.reverse(t1) << endl;
    cout << s.reverse(t2) << endl;
    cout << s.reverse(t3) << endl;
    cin.get();
}