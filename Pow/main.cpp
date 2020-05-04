#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

class Solution
{
public:
    double MyPow(double x, int n)
    {
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        return pow(x, n);
    }

    double pow(double x, int n)
    {
        if (n == 1)
            return x;
        if (n == 0)
            return 1;
        double p = pow(x, n / 2);
        if (n % 2 != 0)
            return p * p * x;
        return p * p;
    }
};

int main()
{
    cout << DBL_MIN;
    cin.get();
}