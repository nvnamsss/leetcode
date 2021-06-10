


using System;
using System.Collections.Generic;
public class Challenge
{
    public static long[] RoundPrices(double[] prices)
    {
        // Type your solution here
        long[] ps = new long[prices.Length];
        double total = 0;
        long ptotal = 0;

        for (int loop = 0; loop < prices.Length; loop++)
        {
            total += prices[loop];
            ps[loop] = (long)Math.Round(prices[loop]);
            ptotal += ps[loop];
        }
        double ddif = total - ptotal;

        if (Math.Abs(ddif) <= 0.5f) return ps;
        Console.WriteLine($"{ddif}");
        double r = 0;

        List<KeyValuePair<int, double>> indices = new List<KeyValuePair<int, double>>();
        for (int loop = 0; loop < prices.Length; loop++)
        {
            double dif = ps[loop] - prices[loop];
            if (ddif < 0 && dif > 0)
            {
                indices.Add(new KeyValuePair<int, double>(loop, dif));
            }

            if (ddif > 0 && dif < 0)
            {
                indices.Add(new KeyValuePair<int, double>(loop, dif));
            }
        }

        indices.Sort((a, b) =>
        {
            return a.Value.CompareTo(b.Value);
        });

        int index = 0;
        while (Math.Abs(ddif) >= 0.5f)
        {
            if (ddif < 0)
            {
                int i = indices[index].Key;
                ps[i] = (long)Math.Ceiling(prices[i]);
                ddif += (ps[i] - prices[i]);
            }
            else
            {
                int i = indices[index].Key;
                ps[i] = (long)Math.Floor(prices[i]);
                ddif += (ps[i] - prices[i]);
            }

            index++;
        }

        return ps;
    }
}
