#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i

class LongestUnequalAdjacentGroupsSubsequenceI {
public:
    // 0 ms, faster than 100% : 29.9 MB, less than 91.02%
    vector<string> solution(vector<string> words, vector<int> groups)
    {
        int n = words.size();
        vector<string> ans = { words[0] };
        for (size_t i = 1; i < n; i++) {
            if (groups[i] != groups[i - 1]) {
                ans.push_back(words[i]);
            } else if (words[i].size() > ans.back().size()) {
                ans.back() = words[i];
            }
        }

        return ans;
    }
    vector<vector<string>> output = {
        { "e", "b" },
        { "a", "b", "c" }
    };
    static constexpr int const& inputs = 2;
    vector<vector<string>> input1 = {
        { "e", "a", "b" },
        { "a", "b", "c", "d" }
    };
    vector<vector<int>> input2 = {
        { 0, 0, 1 },
        { 1, 0, 1, 1 }
    };
};