#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/sort-array-by-increasing-frequency/

class SortArrayByIncreasingFrequency {
public:
    // 0 ms, faster than 100% : 14.72 MB, less than 70.42%
    vector<int> solution(vector<int> nums)
    {
        unordered_map<int, int> m;
        for (auto x : nums)
            m[x]++;

        vector<pair<int, int>> v(begin(m), end(m));
        sort(begin(v), end(v), [&](auto const& a, auto const& b) {
            return a.second != b.second ? a.second < b.second : a.first > b.first;
        });

        int i = 0;
        for (auto& [val, c] : v) {
            while (c--) {
                nums[i++] = val;
            }
        }
        
        return nums;
    }
    vector<vector<int>> output = {
        { 3, 1, 1, 2, 2, 2 },
        { 1, 3, 3, 2, 2 },
        { 5, -1, 4, 4, -6, -6, 1, 1, 1 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 1, 2, 2, 2, 3 },
        { 2, 3, 1, 3, 2 },
        { -1, 1, -6, 4, 5, -6, 1, 4, 1 }
    };
};