#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/tuple-with-same-product

class TupleWithSameProduct {
public:
    // 299 ms, faster than 82.35% : 84.85 MB, less than 81.73%
    int solution(vector<int> nums)
    {
        unordered_map<int, int> m;
        int n = size(nums);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i + 1; j < n; j++) {
                m[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        for (auto [mul, c] : m) {
            if (c < 2)
                continue;

            Printer::print(mul, c);
            ans += 8 * c * (c - 1) / 2;
        }

        return ans;
    }
    vector<int> output = {
        8,
        16
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 3, 4, 6 },
        { 1, 2, 4, 5, 10 }
    };
};