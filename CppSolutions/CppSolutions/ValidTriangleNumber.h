#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/valid-triangle-number

class ValidTriangleNumber {
public:
    // 163 ms, faster than 20.83% : 16.46 MB, less than 95.7%
    int solution(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int k = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin();
                ans += k - j - 1;
            }
        }

        return ans;
    }
    vector<int> output = {
        3,
        4
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 2, 3, 4 },
        { 4, 2, 3, 4 }
    };
};