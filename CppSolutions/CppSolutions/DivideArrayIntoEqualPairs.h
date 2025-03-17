#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/divide-array-into-equal-pairs

class DivideArrayIntoEqualPairs {
public:
    // 0 ms, faster than 100% : 18.07 MB, less than 49.04%
    uint8_t solution(vector<int> nums)
    {
        unordered_map<int, int> f;
        for (int num : nums) {
            f[num]++;
        }
        for (auto& [_, x] : f) {
            if (x % 2 != 0) {
                return false;
            }
        }
        return true;
    }
    vector<uint8_t> output = {
        true,
        false
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, 2, 3, 2, 2, 2 },
        { 1, 2, 3, 4 }
    };
};