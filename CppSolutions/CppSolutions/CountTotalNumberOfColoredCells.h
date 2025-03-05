#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-total-number-of-colored-cells

class CountTotalNumberOfColoredCells {
public:
    // 0 ms, faster than 100% : 7.77 MB, less than 91.36%
    int solution(int n)
    {
        long long ans = 1;
        for (size_t i = 1, c = 4; i < n; i++, c += 4) {
            ans += c;
        }

        return ans;
    }
    vector<int> output = {
        1,
        5
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        1,
        2
    };
};