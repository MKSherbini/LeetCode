#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock

class NumberOfSmoothDescentPeriodsOfAStock {
public:
    // 0 ms, faster than 100% : 106.95 MB, less than 81.34%
    long long solution(vector<int> prices)
    {
        long long ans = 1;
        long long c = 1;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] + 1 == prices[i - 1]) {
                c++;
            } else {
                c = 1;
            }
            ans += c;
        }

        return ans;
    }
    vector<int> output = {
        7,
        4,
        1
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, 2, 1, 4 },
        { 8, 6, 7, 7 },
        { 1 }
    };
};