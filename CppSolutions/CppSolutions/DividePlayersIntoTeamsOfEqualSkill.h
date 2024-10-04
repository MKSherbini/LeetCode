#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/

class DividePlayersIntoTeamsOfEqualSkill {
public:
    // 54 ms, faster than 92.6% : 56.13 MB, less than 97%
    long long solution(vector<int> skill)
    {
        sort(begin(skill), end(skill));
        int i = 0, j = size(skill) - 1;
        int target = skill[i] + skill[j];
        long long ans = 0;
        while (i < j) {
            if (target != skill[i] + skill[j])
                return -1;

            ans += skill[i++] * skill[j--];
        }

        return ans;
    }
    vector<int> output = {
        22,
        12,
        -1
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, 2, 5, 1, 3, 4 },
        { 3, 4 },
        { 1, 1, 2, 3 }
    };
};