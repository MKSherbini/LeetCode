#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-the-number-of-fair-pairs

class CountTheNumberOfFairPairs {
public:
    // 60 ms, faster than 66.07% : 60.25 MB, less than 80.83%
    int solution(vector<int> nums, int lower, int upper)
    {
        sort(begin(nums), end(nums));
        Printer::print(nums);

        // lower <= nums[i] + nums[j] <= upper
        // lower - nums[j] <= nums[i]
        // nums[i] >= lower - nums[j]
        // nums[i] <= upper - nums[j]

        long long ans = 0;
        for (size_t i = 0; i < size(nums); i++) {
            auto it = lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]);
            auto it2 = upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]);
            Printer::print(i, it - begin(nums), it2 - begin(nums));
            ans += it2 - it;
        }

        return ans;
    }

    vector<int> output = {
        6,
        1
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 0, 1, 7, 4, 4, 5 },
        { 1, 7, 9, 2, 5 }
    };
    vector<int> input2 = {
        3,
        11
    };
    vector<int> input3 = {
        6,
        11
    };
};