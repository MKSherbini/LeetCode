#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/three-consecutive-odds/description/

class ThreeConsecutiveOdds {
public:
    // 0 ms, faster than 100% : 10.41 MB, less than 83.42%
    uint8_t solution(vector<int> arr)
    {
        int odds = 0;

        for (auto x : arr) {
            odds = x % 2 ? odds + 1 : 0;
            if (odds == 3)
                return true;
        }

        return false;
    }
    vector<uint8_t> output = {
        false,
        true
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 6, 4, 1 },
        { 1, 2, 34, 3, 4, 5, 7, 23, 12 }
    };
};