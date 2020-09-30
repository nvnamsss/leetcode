/*
You are given equations in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating-point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= equations[i][0], equations[i][1] <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= queries[i][0], queries[i][1] <= 5
equations[i][0], equations[i][1], queries[i][0], queries[i][1] consist of lower case English letters and digits.
*/

using System;
using System.Collections.Generic;

public class Solution {
    public class G {
        public string v;
        public Dictionary<string, double> g;
        public G(string v)
        {
            this.v = v;
            g = new Dictionary<string, double>();
        }

        public double Convert(string a)
        {
            if (g.ContainsKey(a))
            {
                return g[a];
            }

            return -1;
        }

        public void Sync(G g)
        {
            foreach (var item in g.g)
            {
                if (item.Key == v) continue;
                
                if (!this.g.ContainsKey(item.Key))
                {
                    double vv = this.g[g.v];
                    this.g.Add(item.Key, vv * item.Value);
                }
            }
        }

        public override bool Equals(object obj)
        {
            return base.Equals(obj);
        }

        public override int GetHashCode()
        {
            return v.GetHashCode();
        }
        public override string ToString()
        {
            return v;
        }
    }

    public double solve(Dictionary<string, double> variables, List<string> query)
    {
        if (!variables.ContainsKey(query[0]) || !variables.ContainsKey(query[1])) return -1;
        return variables[query[0]] / variables[query[1]];        
    }
    
    public double query(Dictionary<string, G> graph, List<string> query)
    {
        double v1 = 1;
        for (int loop = 1; loop < query[0].Length; loop++)
        {
            v1 *= graph[query[0][loop]].Convert(query[0][0]);
        }

        double v2 = 1;
        for (int loop = 1; loop < query[1].Length; loop++)
        {
            v2 *= graph[query[1][loop]].Convert(query[1][0]);
        }

        v2 *= graph[query[1][0]].Convert(query[0][0]);

        return v1 / v2;
    }

    public double[] CalcEquation(IList<IList<string>> equations, double[] values, IList<IList<string>> queries) {
        List<double> result = new List<double>();
        //graph
        Dictionary<string, G> g = new Dictionary<string, G>();

        //build graph
        for (int loop = 0; loop < values.Length; loop++)
        {
            string a = equations[loop][0];
            string b = equations[loop][1];

            if (!g.ContainsKey(a)) g.Add(a, new G(a));
            if (!g.ContainsKey(b)) g.Add(b, new G(b));

            g[a].g.Add(b, values[loop]);
            g[b].g.Add(a, 1.0 / values[loop]);

            foreach (var item in g[a].g)
            {
                if (g.ContainsKey(item.Key))
                    g[item.Key].Sync(g[b]);
            }
        }

        foreach (var query in queries)
        {
            result.Add(solve(variables, query));    
        }

        return result.ToArray();        
    }
}