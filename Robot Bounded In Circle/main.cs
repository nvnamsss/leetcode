/*
On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: "GGLLGG"
Output: true
Explanation: 
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
Example 2:

Input: "GG"
Output: false
Explanation: 
The robot moves north indefinitely.
Example 3:

Input: "GL"
Output: true
Explanation: 
The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

Note:

1 <= instructions.length <= 100
instructions[i] is in {'G', 'L', 'R'}
*/

using System;
using System.Collections.Generic;

public class Solution
{
    struct Vector2
    {
        public int x;
        public int y;
        public Vector2(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public static Vector2 Rotate(Vector2 vector, float degrees)
        {
            float sin = (float)Math.Sin(degrees * Math.PI / 180f);
            float cos = (float)Math.Cos(degrees * Math.PI / 180f);

            Vector2 v;
            v.x = (cos * vector.x) - (sin * vector.y);
            v.y = (sin * vector.x) + (cos * vector.y);
            return v;
        }

        public static Vector2 operator -(Vector2 lhs, Vector2 rhs)
        {
            Vector2 rs;
            rs.x = lhs.x - rhs.x;
            rs.y = lhs.y - rhs.y;
            return rs;
        }
        
        public static Vector2 operator +(Vector2 lhs, Vector2 rhs)
        {
            Vector2 rs;
            rs.x = lhs.x + rhs.x;
            rs.y = lhs.y + rhs.y;
            return rs;
        }
    }

    float rotation;
    Vector2 location;
    Vector2 direction;
    private Vector2 Simulate(string instructions)
    {
        for (int loop = 0; loop < instructions.Length; loop++)
        {
            char order = instructions[loop];
            switch (order)
            {
                case 'G':
                    location += direction;
                    break;
                case 'L':
                    direction = Vector2.Rotate(direction, -90);
                    rotation -= 90;
                    break;
                case 'R':
                    direction = Vector2.Rotate(direction, 90);
                    rotation += 90;

                    break;
            }
        }

        return location;
    }

    public bool IsRobotBounded(string instructions)
    {
        rotation = 0;
        location = new Vector2();
        direction = new Vector2(0, 1);
        Simulate(instructions);

        if (location.x != 0 && location.y != 0 && direction.x == 0 && direction.y == 1) return false;
        // if (location.y == 0 && rotation != 0) return true;
        
        // return location.y == 0;
        return rotation == 0;
    }
}