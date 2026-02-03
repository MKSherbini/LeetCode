#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/trionic-array-i

class TrionicArrayI {
public:
    // 0 ms, faster than 100% : 27.57 MB, less than 96.65%
    uint8_t solution(vector<int> nums)
    {
        int n = nums.size();

        int state = -1;
        // -1 - start, 0 - increasing, 1 - decreasing, 2 - increasing
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1])
                return false;

            if (nums[i] > nums[i - 1]) {
                if (state == -1)
                    state = 0;
                if (state == 1)
                    state = 2;
            }
            if (nums[i] < nums[i - 1]) {
                if (state == -1 || state == 2)
                    return false;
                if (state == 0)
                    state = 1;
            }
        }

        return state == 2;
    }
    vector<uint8_t> output = {
        true,
        false
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 3, 5, 4, 2, 6 },
        { 2, 1, 3 }
    };
};