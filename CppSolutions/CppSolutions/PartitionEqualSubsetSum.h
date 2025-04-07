#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum

class PartitionEqualSubsetSum {
public:
    // 403 ms, faster than 5% : 100.3 MB, less than 45.21%
    uint8_t solution(vector<int> nums)
    {
        int n = nums.size();
        auto sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) {
            return false;
        }

        vector mem(n, vector<int>(sum / 2 + 1, -1));
        function<int(int, int)> f = [&](int i, int s) -> bool {
            if (s < 0)
                return false;
            if (s == 0)
                return true;
            if (i >= n)
                return false;
            if (mem[i][s] != -1)
                return mem[i][s];

            return mem[i][s] = f(i + 1, s) | f(i + 1, s - nums[i]);
        };

        return f(0, sum / 2);
    }
    vector<uint8_t> output = {
        true,
        false
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 5, 11, 5 },
        { 1, 2, 3, 5 }
    };
};