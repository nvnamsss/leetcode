using System;
class Solution
{
    public int Atoi(string str)
    {
        int value = 0;
        int sign = 1;
        str = str.Trim();
        if (str.Length == 0) return value;

        if (str[0] == '-')
        {
            sign = -1;
            str = str.Remove(0, 1);
        } else if (str[0] == '+')
        {
            sign = 1;
            str = str.Remove(0, 1);
        }

        for (int loop = 0; loop < str.Length; loop++)
        {
            if (str[loop] >= '0' && str[loop] <= '9')
            {
                if (value != 0 && ((int.MaxValue / value) < 10 || int.MaxValue / value == 10 & int.MaxValue % value < str[loop] - 48))
                {
                    if (sign) return int.MaxValue;
                    return int.MinValue;
                }

                value = value * 10 + (str[loop] - 48);
            }
            else {
                return value * sign;
            }
        }

        return value * sign;
    }
}