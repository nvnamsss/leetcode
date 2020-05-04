#include <iostream>
#include <algorithm>
#include <cctype>
#include <locale>
#include <string>
#include <functional>
#include <cmath>
using namespace std;

class Solution
{
public:
    // trim from start (in place)
    // trim from start
    static inline std::string &ltrim(std::string &s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                        std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }

    // trim from end
    static inline std::string &rtrim(std::string &s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(),
                             std::not1(std::ptr_fun<int, int>(std::isspace)))
                    .base(),
                s.end());
        return s;
    }

    // trim from both ends
    static inline std::string &trim(std::string &s)
    {
        return ltrim(rtrim(s));
    }

    int myAtoi(string str)
    {
        string s = trim(str);
        int value = 0;
        int length = s.length();
        if (length == 0)
            return value;
        int sign = 1;
        int start = 0;
        if (s[0] == '-')
        {
            sign = -1;
            start = 1;
        }

        if (s[0] == '+')
        {
            sign = -1;
            start = 1;
        }

        for (int loop = start; loop < length; loop++)
        {
            /* code */
            if (s[loop] >= 48 && s[loop] <= 59)
            {
                if (value != 0 && (INT_MAX / value < 10 || (INT_MAX / value == 10 && INT_MAX % value < s[loop] - 48)))
                {
                    if (sign == 1) return INT_MAX;
                    return INT_MIN;
                }
                else
                {
                    value = value * 10 + (s[loop] - 48);
                }
            }
            else{
                return value * sign;
            }
        }

        value = value * sign;
        cout << value;
        return value;
    }
};

int main()
{
    Solution s = Solution();
    // string test1("123");
    // string test2 = "-111";
    // string test3 = "91283472332";
    // string test4 = "-91283472332";

    int v1 = s.myAtoi("123232");
    // int v2 = s.myAtoi(test2);
    // int v3 = s.myAtoi(test3);
    // int v4 = s.myAtoi(test4);

    // cout << v1 << endl;
    // cout << v2 << endl;
    // cout << v3 << endl;
    // cout << v4 << endl;
    cin.get();
}