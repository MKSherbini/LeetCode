#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/

class CountNumberOfMaximumBitwiseOrSubsets {
public:
    // 51 ms, faster than 36.83% : 10.94 MB, less than 28.7%
    int solution(vector<int> nums)
    {
        int n = size(nums);
        int mx = -1, cnt = 0;
        function<void(int, int)> f = [&](int i, int acc) -> void {
            if (i == n) {
                if (acc == mx) {
                    cnt++;
                } else if (acc > mx) {
                    mx = acc, cnt = 1;
                }
                return;
            }

            f(i + 1, acc), f(i + 1, acc | nums[i]);
        };
        f(0, 0);

        return cnt;
    }
    vector<int> output = {
        2,
        7,
        6
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, 1 },
        { 2, 2, 2 },
        { 3, 2, 1, 5 }
    };
};