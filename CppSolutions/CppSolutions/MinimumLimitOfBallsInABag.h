#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag

class MinimumLimitOfBallsInABag {
public:
    // 61 ms, faster than 17.11% : 59.61 MB, less than 28.46%
    int solution(vector<int> nums, int maxOperations)
    {
        int l = 1, r = *max_element(begin(nums), end(nums));

        auto f = [&](int mx) {
            int cnt = 0;
            for (auto x : nums) {
                cnt += ceil(1. * x / mx) - 1;
                if (cnt > maxOperations)
                    return 0;
            }

            return 1;
        };

        while (l < r) {
            int md = l + (r - l) / 2;
            auto t = f(md);
            Printer::print(l, r);
            if (t) {
                r = md;
            } else {
                l = md + 1;
            }
        }

        return l;
    }
    vector<int> output = {
        3,
        2
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 9 },
        { 2, 4, 8, 2 }
    };
    vector<int> input2 = {
        2,
        4
    };
};