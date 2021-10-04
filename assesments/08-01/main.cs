using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public string LicenseKeyFormatting(string s, int k)
    {
        string[] group = s.Split('-');
        string result = string.Empty;
        int toUpper = 'a' - 'A';
        int m = k;
        int start = (s.Length - (group.Length - 1)) % k;

        for (int loop = 0; loop < start; loop++)
        {
            char append = group[0][loop];
            if (append >= 'a' && append <= 'z')
            {
                append = (char)(append - toUpper);
            }
            result = result + append;
        }

        int i = 0;
        int j = start;

        while (i < group.Length)
        {
            while (j < group[i].Length)
            {
                if (m == k)
                {
                    result = result + '-';
                }
                char append = group[i][j];
                if (append >= 'a' && append <= 'z')
                {
                    append = (char)(append - toUpper);
                }

                result = result + append;
                m--;
                if (m == 0)
                {
                    m = k;
                }
                j++;
            }
            i++;
        }
        // for (int i = 1; i < group.Length; i++)
        // {
        //     for (int j = 0; j < group[i].Length; j++)
        //     {

        //     }
        // }

        return result;
    }

    public int LengthLongestPath(string input)
    {
        string[] path = input.Split('\n');
        string p = string.Empty;
        return recursive(path, p, 0, -1);
    }

    private int recursive(string[] path, string p, int i, int d)
    {
        int max = p.Replace("\t", "").Replace("\n", "").Length;
        for (int loop = i; loop < path.Length; loop++)
        {
            int c = 0;
            while (path[loop][c + 1] == '\t')
            {
                c++;
            }

            if (c > d)
            {
                p = p + path[loop];
                if (isDirectory(path[loop]))
                {
                    max = Math.Max(max, recursive(path, p, loop + 1, c));
                    if (max == 24) Console.WriteLine(p);
                }
                else
                {
                    max = Math.Max(max, p.Replace("\t", "").Replace("\n", "").Length);
                }
            }
            else
            {
                break;
            }
        }

        return max;
    }

    private bool isDirectory(string name)
    {
        return !name.Contains('.');
    }
    struct info
    {
        public int index;
        public string transaction;
        public info(int index, string transaction)
        {
            this.index = index;
            this.transaction = transaction;
        }
    }

    public IList<string> InvalidTransactions(string[] transactions)
    {
        bool[] invalid = new bool[transactions.Length];
        List<string> rs = new List<string>();
        Dictionary<string, List<info>> map = new Dictionary<string, List<info>>();
        for (int loop = 0; loop < transactions.Length; loop++)
        {
            string[] info = transactions[loop].Split(",");
            string name = info[0];
            int time = int.Parse(info[1]);
            int amount = int.Parse(info[2]);
            string city = info[3];

            if (!map.ContainsKey(name))
            {
                map.Add(name, new List<info>());
            }
            else
            {
                List<info> tx = map[name];
                for (int loop2 = 0; loop2 < tx.Count; loop2++)
                {
                    string[] info2 = tx[loop2].transaction.Split(",");
                    string name2 = info2[0];
                    int time2 = int.Parse(info2[1]);
                    int amount2 = int.Parse(info2[2]);
                    string city2 = info2[3];
                    if (name == name2 && city != city2 && Math.Abs(time - time2) <= 60)
                    {
                        if (!invalid[loop])
                        {
                            rs.Add(transactions[loop]);
                            invalid[loop] = true;
                        }

                        if (!invalid[tx[loop2].index])
                        {
                            rs.Add(tx[loop2].transaction);
                            invalid[tx[loop2].index] = true;
                        }
                    }
                }
            }
            if (amount > 1000)
            {
                if (!invalid[loop])
                {
                    rs.Add(transactions[loop]);
                    invalid[loop] = true;
                }

            }
            map[name].Add(new info(loop, transactions[loop]));
        }

        return rs;
    }

    public int TwoCitySchedCost(int[][] costs)
    {
        List<KeyValuePair<int, int>> v = new List<KeyValuePair<int, int>>();
        for (int i = 0; i < costs.Length; i++)
        {
            v.Add(new KeyValuePair<int, int>(costs[i][0], costs[i][1]));
        }

        v.Sort((a, b) =>
        {
            return (a.Value - b.Value).CompareTo(a.Key - b.Value);
        });

        int total = 0;
        for (int i = 0; i < v.Count / 2; i++)
        {
            total += v[i].Key;
        }

        for (int i = v.Count / 2; i < v.Count; i++)
        {
            total += v[i].Value;
        }

        return total;
    }
}