/*
You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
Example 3:

Input: trips = [[2,1,5],[3,5,7]], capacity = 3
Output: true
Example 4:

Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
Output: true
 
 

Constraints:

trips.length <= 1000
trips[i].length == 3
1 <= trips[i][0] <= 100
0 <= trips[i][1] < trips[i][2] <= 1000
1 <= capacity <= 100000
*/

using System;
using System.Collections.Generic;
public class Solution {
    struct Milestone {
        public int at;
        public int capacity;

        public Milestone(int capacity, int at)
        {
            this.at = at;
            this.capacity = capacity;
        }
    }
    public bool CarPooling(int[][] trips, int capacity) {
        List<Milestone> milestones = new List<Milestone>();
        for (int loop = 0; loop < trips.Length; loop++)
        {
            int cap = trips[loop][0];
            int atpick = trips[loop][1];
            int atdrop = trips[loop][2];

            Milestone mpick = new Milestone(cap, atpick);
            Milestone mdrop = new Milestone(-cap, atdrop);
            milestones.Add(mpick);
            milestones.Add(mdrop);
        }       

        milestones.Sort((a, b)=> {
            if (a.at == b.at) return a.capacity.CompareTo(b.capacity);
            return a.at.CompareTo(b.at);
        });
        
        int c= 0;
        for (int loop = 0; loop < milestones.Count; loop++)
        {
            c += milestones[loop].capacity;
            if (c > capacity) return false;
        }

        return true;
    }
}