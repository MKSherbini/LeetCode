#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits

class MaxSumOfAPairWithEqualSumOfDigits {
public:
    // 31 ms, faster than 46.93% : 63.56 MB, less than 98.5%
    int solution(vector<int> nums)
    {
        vector<int> v(90, -1);
        sort(begin(nums), end(nums), greater());
        Printer::print(nums);
        int n = size(nums);
        int ans = -1;
        for (size_t i = 0; i < n; i++) {
            int sum = 0, x = nums[i];
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            Printer::print(v[sum], nums[i]);
            if (v[sum] == -1) {
                v[sum] = nums[i];
            } else if (v[sum] != -2) {
                ans = max(ans, v[sum] + nums[i]);
                v[sum] = -2;
            }
        }

        return ans;
    }
    vector<int> output = {
        54,
        -1,
        835
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 18, 43, 36, 13, 7 },
        { 10, 12, 19, 14 },
        { 368, 369, 307, 304, 384, 138, 90, 279, 35, 396, 114, 328, 251, 364, 300, 191, 438, 467, 183 }
    };
};