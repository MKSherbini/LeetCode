#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii

class MaximumValueOfAnOrderedTripletII {
public:
    // 0 ms, faster than 100% : 95.33 MB, less than 72.7%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        vector<int> pre(n);

        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], nums[i - 1]);
        }

        int mx = nums.back();
        long long ans = 0;
        for (int i = n - 2; i > 0; i--) {
            ans = max(ans, 1LL * mx * (pre[i] - nums[i]));
            Printer::print(pre[i], nums[i], mx, (pre[i] - nums[i]) * mx);
            mx = max(mx, nums[i]);
        }

        return ans;
    }
    vector<int> output = {
        77,
        133,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 12, 6, 1, 2, 7 },
        { 1, 10, 3, 4, 19 },
        { 1, 2, 3 }
    };
};