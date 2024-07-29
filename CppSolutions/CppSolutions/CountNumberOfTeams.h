#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-number-of-teams/description/

class CountNumberOfTeams {
public:
    // 26 ms, faster than 84.19% : 11.88 MB, less than 35.83%
    int solution(vector<int> rating)
    {
        int n = size(rating);
        int ans = 0;
        vector<int> hasLess(n, 0), hasMore(n, 0);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < i; j++) {
                if (rating[j] < rating[i]) {
                    hasLess[i]++;
                    ans += hasLess[j];
                }
                if (rating[j] > rating[i]) {
                    hasMore[i]++;
                    ans += hasMore[j];
                }
            }
        }

        return ans;
    }
    vector<int> output = {
        3,
        0,
        4
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 5, 3, 4, 1 },
        { 2, 1, 3 },
        { 1, 2, 3, 4 }
    };
};