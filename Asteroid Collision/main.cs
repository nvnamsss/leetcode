/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.
 

Constraints:

1 <= asteroids <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/

using System;
using System.Collections.Generic;
public class Solution
{

    public void Print(int[] asteroids)
    {
        Console.WriteLine();
        for (int loop = 0; loop < asteroids.Length; loop++)
        {
            Console.Write($"{asteroids[loop]}\t");
        }
    }

    public int[] AsteroidCollision(int[] asteroids)
    {
        Stack<int> s = new Stack<int>();
        for (int loop = 0; loop < asteroids.Length; loop++)
        {
            bool crash = false;
            while (s.Count > 0 && asteroids[loop] < 0 && s.Peek() > 0)
            {
                int w1 = Math.Abs(asteroids[loop]);
                int w2 = s.Peek();
                if (w2 < w1)
                {
                    s.Pop();
                    continue;
                }
                if (w2 == w1)
                {
                    s.Pop();
                }
                crash = true;
                break;
            }
            if (!crash) s.Push(asteroids[loop]);
        }
        int[] r = new int[s.Count];
        for (int loop = r.Length - 1; loop >= 0; loop--)
        {
            r[loop] = s.Pop();
        }
        return r;

        List<int> alive = new List<int>();

        for (int loop = 0; loop < asteroids.Length; loop++)
        {
            if (asteroids[loop] > 0)
            {
                alive.Add(asteroids[loop]);
            }
            else
            {
                bool crash = false;
                int w = Math.Abs(asteroids[loop]);
                for (int loop2 = alive.Count - 1; loop2 >= 0; loop2--)
                {
                    if (alive[loop2] < 0) continue;
                    int w2 = Math.Abs(alive[loop2]);
                    if (w2 < w)
                    {
                        alive.RemoveAt(loop2);
                        continue;
                    }

                    if (w2 == w)
                    {
                        alive.RemoveAt(loop2);
                        crash = true;
                        break;
                    }

                    if (w2 > w)
                    {
                        crash = true;
                        break;
                    }
                }

                if (!crash) alive.Add(asteroids[loop]);
            }

        }
        return alive.ToArray();
    }
}