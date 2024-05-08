#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/relative-ranks/description/

class RelativeRanks {
public:
    // 3 ms, faster than 96.77% : 14.19 MB, less than 63.13%
    vector<string> solution(vector<int> score)
    {
        int n = size(score);
        unordered_map<int, int> m;
        for (size_t i = 0; i < n; i++) {
            m[score[i]] = i;
        }
        sort(begin(score), end(score), greater());
        vector<string> medals = { "Gold Medal", "Silver Medal", "Bronze Medal" };

        vector<string> ans(n);
        for (size_t i = 0; i < n; i++) {
            ans[m[score[i]]] = i < 3 ? medals[i] : to_string(i + 1);
        }

        return ans;
    }
    vector<vector<string>> output = {
        { "Gold Medal", "Silver Medal", "Bronze Medal", "4", "5" },
        { "Gold Medal", "5", "Bronze Medal", "Silver Medal", "4" }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 5, 4, 3, 2, 1 },
        { 10, 3, 8, 9, 4 }
    };
};