#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/sort-colors/description/

class SortColors {
public:
    // 0 ms, faster than 100% : 9.68 MB, less than 95.13%
    vector<int> solution(vector<int> nums)
    {
        vector<int> f(3);
        for (auto x : nums)
            f[x]++;

        int i = 0;
        for (size_t j = 0; j < 3; j++) {
            while (f[j]--) {
                nums[i++] = j;
            }
        }

        return nums;
    }
    vector<vector<int>> output = {
        { 0, 0, 1, 1, 2, 2 },
        { 0, 1, 2 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 0, 2, 1, 1, 0 },
        { 2, 0, 1 }
    };
};