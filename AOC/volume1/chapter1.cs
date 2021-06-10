using System;

public class Chapter1
{
    /*
        Suppose that we have a binary computer and a number x, 1 <= x < 2
        Show that the following algorithm which uses only shifting, addition, and subtraction operations proportional
        to the number of places of accuracy desired, may be used to calculate an approximation to y = logb(x)
    */
    public float Logarithm(int b, int x)
    {
        int y = x;
        int z = x << 1;
        int k = 1;

        while (true)
        {
            if (x == 1) return x;
            while (x - z < 1)
            {
                z = z << 1;
                k = k + 1;
            }

            x = x - z;
            z = x << k;
            int sk = (int)Math.Pow(2, k);
            y = y + (int)Logarithm(b, sk / (sk - 1));
        }
    }
}
