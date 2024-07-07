#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/water-bottles/description/

class WaterBottles {
public:
    // 0 ms, faster than 100% : 6.97 MB, less than 95.58%
    int solution(int numBottles, int numExchange)
    {
        int ans = 0, c = 0;
        while (numBottles) {
            ans += numBottles;
            numBottles += c;
            c=numBottles%numExchange;
            numBottles /= numExchange;
        }

        return ans;
    }
    vector<int> output = {
        13,
        19
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        9,
        15
    };
    vector<int> input2 = {
        3,
        4
    };
};