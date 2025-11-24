#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/binary-prefix-divisible-by-5

class BinaryPrefixDivisibleBy5 {
public:
    // 0 ms, faster than 100% : 18.32 MB, less than 69.4%
    vector<uint8_t> solution(vector<int> nums)
    {
        vector<uint8_t> ans;
        int prefix = 0;
        for (int bit : nums) {
            prefix = ((prefix << 1) + bit) % 10;
            ans.push_back(prefix % 5 == 0);
        }
        return ans;
    }
    vector<vector<uint8_t>> output = {
        { true, false, false },
        { false, false, false }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 0, 1, 1 },
        { 1, 1, 1 }
    };
};