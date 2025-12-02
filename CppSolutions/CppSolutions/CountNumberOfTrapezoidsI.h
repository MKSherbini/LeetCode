#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-number-of-trapezoids-i

class CountNumberOfTrapezoidsI {
public:
    // 54 ms, faster than 93.87% : 191.42 MB, less than 90.93%
    int solution(vector<vector<int>> points)
    {
        unordered_map<int, int> ys;
        for (const auto& p : points) {
            ys[p[1]]++;
        }

        const int MOD = 1e9 + 7;
        long long ans = 0;
        long long sum = 0;
        for (const auto& [_, c] : ys) {
            Printer::print(c, (c * (c - 1)) / 2);
            if (c >= 2) {
                int x = 1ll * c * (c - 1) / 2;
                ans += sum * x;
                ans %= MOD;
                sum += x;
                sum %= MOD;
            }
        }

        return ans;
    }
    // x*y x*z y*z = x(y+z) y*z

    vector<int> output = {
        3,
        1
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 0 }, { 2, 0 }, { 3, 0 }, { 2, 2 }, { 3, 2 } },
        { { 0, 0 }, { 1, 0 }, { 0, 1 }, { 2, 1 } }
    };
};