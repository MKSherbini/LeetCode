#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/transformed-array

class TransformedArray {
public:
    // 0 ms, faster than 100% : 25.46 MB, less than 98.89%
    vector<int> solution(vector<int> nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[(i + nums[i] % n + n) % n];
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 1, 1, 1, 3 },
        { -1, -1, 4 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, -2, 1, 1 },
        { -1, 4, -1 }
    };
};