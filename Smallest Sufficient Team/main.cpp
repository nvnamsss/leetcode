/*
In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.

Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.

For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.

It is guaranteed an answer exists.

 

Example 1:

Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]
Example 2:

Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]
 

Constraints:

1 <= req_skills.length <= 16
1 <= req_skills[i].length <= 16
req_skills[i] consists of lowercase English letters.
All the strings of req_skills are unique.
1 <= people.length <= 60
0 <= people[i].length <= 16
1 <= people[i][j].length <= 16
people[i][j] consists of lowercase English letters.
All the strings of people[i] are unique.
Every skill in people[i] is a skill in req_skills.
It is guaranteed a sufficient team exists.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skillIds;
        vector<int> personSkillMask = vector<int>(people.size());
        for (int i = 0; i < req_skills.size(); i++)
        {
            skillIds[req_skills[i]] = i;
        }
        
        for (int i = 0; i < people.size(); i++)
        {
            for (int j = 0; j < people[i].size(); j++)
            {
                string skill = people[i][j];
                personSkillMask[i] |= (1 << skillIds[skill]);
            }
        }
        
        int skillVariationLength = 1 << req_skills.size();
        long peopleVariationLength = 1l << people.size();

        vector<long> dp = vector<long>(skillVariationLength, peopleVariationLength - 1);
        dp[0] = 0;
        // intuitionly, denote k is the current state then for each people we have
        // k = k' | personSkill
        // then count = count(k') + 1
        // skillMask is k so k' is skillMask exclude personSkill
        // if k' is difference from k, it implies that this person will going to contribute to this state.
        for (int skillMask = 1; skillMask < skillVariationLength; skillMask++)
        {
            for (int i = 0; i < people.size(); i++)
            {
                int smallerSkillMask = skillMask & ~personSkillMask[i]; // this k'
                if (smallerSkillMask != skillMask) {
                    long peopleMask = dp[smallerSkillMask] | (1l << i); // include this person
                    int peopleRequired = __builtin_popcountl(peopleMask);
                    int currentPeopleRequired = __builtin_popcountl(dp[skillMask]);
                    if (peopleRequired < currentPeopleRequired) {
                        dp[skillMask] = peopleMask;
                    }
                }
            }
        }

        vector<int> ans;
        long answerMask = dp[skillVariationLength - 1];
        for (int i = 0; i < people.size(); i++)
        {
            if (answerMask & (1 << i)) {
                ans.push_back(i);
            }
        }
        return ans;           
    }
};

int main() {
    Solution s;
    vector<string> skills = {"java","nodejs","reactjs"};
    vector<vector<string>> people = {{"java"},{"nodejs"},{"nodejs","reactjs"}};
    s.smallestSufficientTeam(skills, people);
}