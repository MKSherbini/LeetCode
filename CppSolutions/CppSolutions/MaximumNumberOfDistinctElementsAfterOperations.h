#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations

class MaximumNumberOfDistinctElementsAfterOperations {
public:
    // 106 ms, faster than 94.95% : 97.54 MB, less than 88.33%
    int solution(vector<int> nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int last = nums[0] - k;
        int ans = 1;
        for (size_t i = 1; i < n; i++) {
            if (nums[i] + k <= last) {
                continue;
            }
            last = max(nums[i] - k, last + 1);
            ans++;
        }

        return ans;
    }
    vector<int> output = {
        6,
        3
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2, 2, 3, 3, 4 },
        { 4, 4, 4, 4 }
    };
    vector<int> input2 = {
        2,
        1
    };
};