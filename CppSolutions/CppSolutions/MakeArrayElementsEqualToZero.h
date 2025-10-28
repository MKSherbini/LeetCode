#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/make-array-elements-equal-to-zero

class MakeArrayElementsEqualToZero {
public:
    // 0 ms, faster than 100% : 22.49 MB, less than 53.67%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        vector<int> post(n);
        post.back() = nums.back();
        for (int i = n - 2; i >= 0; i--) {
            post[i] = post[i + 1] + nums[i];
        }

        int pre = nums[0];
        int ans = nums[0] == 0 && post[0] <= 1 ? 2 - post[0] : 0;
        for (int i = 1; i < n; i++) {
            pre += nums[i];
            if (nums[i] == 0 && abs(pre - post[i]) <= 1) {
                ans += 2 - abs(pre - post[i]);
                Printer::print(pre, post[i]);
            }
        }

        return ans;
    }
    vector<int> output = {
        2,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 0, 2, 0, 3 },
        { 2, 3, 4, 0, 4, 1, 0 }
    };
};