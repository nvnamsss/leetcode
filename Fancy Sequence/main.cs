/*
Write an API that generates fancy sequences using the append, addAll, and multAll operations.

Implement the Fancy class:

Fancy() Initializes the object with an empty sequence.
void append(val) Appends an integer val to the end of the sequence.
void addAll(inc) Increments all existing values in the sequence by an integer inc.
void multAll(m) Multiplies all existing values in the sequence by an integer m.
int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.
 

Example 1:

Input
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
Output
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

Explanation
Fancy fancy = new Fancy();
fancy.append(2);   // fancy sequence: [2]
fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
fancy.append(7);   // fancy sequence: [5, 7]
fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // return 10
fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
fancy.append(10);  // fancy sequence: [13, 17, 10]
fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // return 26
fancy.getIndex(1); // return 34
fancy.getIndex(2); // return 20
 

Constraints:

1 <= val, inc, m <= 100
0 <= idx <= 105
At most 105 calls total will be made to append, addAll, multAll, and getIndex.
*/

using System;
using System.Collections.Generic;
using System.Numerics;
using System.Linq;
public class Fancy
{
    List<BigInteger> ms = new List<BigInteger>();
    List<BigInteger> incs = new List<BigInteger>();
    public static int MOD = (int)(1e9 + 7);
    List<BigInteger> values;

    // Operation currentOperation;
    public Fancy()
    {
        values = new List<BigInteger>();    
        ms = new List<BigInteger>();
        incs = new List<BigInteger>();
        ms.Add(1);
        incs.Add(0);
    }

    public void Append(int val)
    {
        values.Add(val);
        ms.Add(ms[ms.Count - 1]);
        incs.Add(incs[incs.Count - 1]);
    }

    public void AddAll(int inc)
    {
        int last = incs.Count - 1;
        incs[last] = incs[last] + inc;
    }

    public void MultAll(int m)
    {
        int last = ms.Count - 1;
        ms[last] = ms[last] * m;
        incs[last] = incs[last] * m;
    }

    public int GetIndex(int idx)
    {
        if (idx < 0 || idx >= values.Count) return -1;

        int last = ms.Count - 1;
        BigInteger m = ms[last] / ms[idx];
        BigInteger inc = incs[last] - incs[idx] * m;
        BigInteger v = values[idx] * m + inc ;

        return (int)(v % MOD);
    }

        public long PowMod(long x, long y, long mod)
    {
        long res = 1;
        while (y > 0)
        {
            if ((y & 1) == 1)
                res = res * x % mod;
            x = x * x % mod;
            y >>= 1;
        }

        return res;
    }
}

public class Fancy2{
    public static int mod97 = (int)Math.Pow(10, 9) + 7;
    List<int> values = new List<int>();
    List<long> ms = new List<long>();
    List<long> incs = new List<long>();

    public Fancy2() {
        ms.Add(1);
        incs.Add(0);
    }
public void Append(int val)
    {
        values.Add(val);
        ms.Add(ms.Last());
        incs.Add(incs.Last());
    }

    public void AddAll(int inc)
    {
        incs[incs.Count - 1] = (incs.Last() + inc) % mod97;
    }

    public void MultAll(int m)
    {
        ms[ms.Count - 1] = ms.Last() * m % mod97;
        incs[incs.Count - 1] = incs.Last() * m % mod97;
    }

    public int GetIndex(int idx)
    {
        if (idx >= values.Count)
            return -1;
        
        //Given Fermat Little Theorem 
        //   1 ≡ a^(m-1) (mod m) 
        //=> a^-1 ≡ a^(m-2) (mod m)
        //Let a = mul[idx], m = mod97
        //So mul.Last()/mul[idx] 
        //=> mul.Last()*mul[idx]^-1 
        //=> mul.Last()*mul[idx]^(mod-2) 
        //=> mul.Last() * PowMod(mul[idx], mod97 - 2, mod97)
        long m = ms.Last() * PowMod(ms[idx], mod97 - 2, mod97) % mod97;
        long inc = incs.Last() + mod97 - incs[idx] * m % mod97;
        return (int)((values[idx] * m + inc) % mod97);
    }
    public long PowMod(long x, long y, long mod)
    {
        long res = 1;
        while (y > 0)
        {
            if ((y & 1) == 1)
                res = res * x % mod;
            x = x * x % mod;
            y >>= 1;
        }

        return res;
    }
}
/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy obj = new Fancy();
 * obj.Append(val);
 * obj.AddAll(inc);
 * obj.MultAll(m);
 * int param_4 = obj.GetIndex(idx);
 */