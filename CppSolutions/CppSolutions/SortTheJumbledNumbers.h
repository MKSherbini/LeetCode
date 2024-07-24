#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/sort-the-jumbled-numbers/description/

class SortTheJumbledNumbers {
public:
    // 459 ms, faster than 31.08% : 76.48 MB, less than 97.21%
    vector<int> solution(vector<int> mapping, vector<int> nums)
    {
        auto conv = [&](int x) {
            if (!x)
                return mapping[x];

            int res = 0;
            int mul = 1;
            while (x) {
                res += mul * mapping[(x % 10)];
                x /= 10;
                mul *= 10;
            }
            return res;
        };
        sort(begin(nums), end(nums), [&](const int a, const int b) {
            return conv(a) < conv(b);
        });

        return nums;
    }
    vector<vector<int>> output = {
        { 338, 38, 991 },
        { 123, 456, 789 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 8, 9, 4, 0, 2, 1, 3, 5, 7, 6 },
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
    };
    vector<vector<int>> input2 = {
        { 991, 338, 38 },
        { 789, 456, 123 }
    };
};