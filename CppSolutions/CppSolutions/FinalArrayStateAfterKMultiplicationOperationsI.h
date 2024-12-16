#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i

class FinalArrayStateAfterKMultiplicationOperationsI {
public:
    // 0 ms, faster than 100% : 27.22 MB, less than 39.18%
    vector<int> solution(vector<int> nums, int k, int multiplier)
    {
        int n = size(nums);
        auto cmp = [&](const auto i, const auto j) {
            return nums[i] == nums[j] ? i > j : nums[i] > nums[j];
        };

        priority_queue<int, vector<int>, decltype(cmp)>
            pq(cmp);
        for (size_t i = 0; i < n; i++) {
            pq.push(i);
        }

        while (k--) {
            auto i = pq.top();
            pq.pop();
            nums[i] *= multiplier;
            pq.push(i);
        }

        return nums;
    }
    vector<vector<int>> output = {
        { 8, 4, 6, 5, 6 },
        { 16, 8 }
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 2, 1, 3, 5, 6 },
        { 1, 2 }
    };
    vector<int> input2 = {
        5,
        3
    };
    vector<int> input3 = {
        2,
        4
    };
};