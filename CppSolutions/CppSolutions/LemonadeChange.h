#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/lemonade-change/description/

class LemonadeChange {
public:
    // 66 ms, faster than 81.16% : 85.84 MB, less than 63.29%
    uint8_t solution(vector<int> bills)
    {
        int c5 = 0, c10 = 0;
        for (auto x : bills) {
            if (x == 5)
                c5++;
            else if (x == 10 && c5)
                c5--, c10++;
            else if (x == 20 && c5 && c10)
                c5--, c10--;
            else if (x == 20 && c5 >= 3)
                c5 -= 3;
            else
                return false;
        }

        return true;
    }
    vector<uint8_t> output = {
        true,
        false
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 5, 5, 5, 10, 20 },
        { 5, 5, 10, 10, 20 }
    };
};