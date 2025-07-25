#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion

class MaximumUniqueSubarraySumAfterDeletion {
public:
    // 0 ms, faster than 100% : 29.39 MB, less than 86.99%
    int solution(vector<int> nums)
    {
        unordered_set<int> s;
        int ans = 0, mx = INT_MIN;
        for (auto& num : nums) {
            mx = max(mx, num);
            if (num > 0 && !s.count(num)) {
                s.insert(num);
                ans += num;
            }
        }

        return ans == 0 ? mx : ans;
    }
    vector<int> output = {
        15,
        1,
        3,
        -100
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 4, 5 },
        { 1, 1, 0, 1, 1 },
        { 1, 2, -1, -2, 1, 0, -1 },
        { -100 }
    };
};