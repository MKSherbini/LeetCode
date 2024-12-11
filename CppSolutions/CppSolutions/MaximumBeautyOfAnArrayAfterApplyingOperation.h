#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation

class MaximumBeautyOfAnArrayAfterApplyingOperation {
public:
    // 39 ms, faster than 87.31% : 104.83 MB, less than 94.06%
    int solution(vector<int> nums, int k)
    {
        sort(begin(nums), end(nums));

        int n = size(nums);
        int i = 0;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            while (i < j && nums[i] + k < nums[j] - k) {
                i++;
            }
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
    vector<int> output = {
        3,
        4
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 4, 6, 1, 2 },
        { 1, 1, 1, 1 }
    };
    vector<int> input2 = {
        2,
        10
    };
};