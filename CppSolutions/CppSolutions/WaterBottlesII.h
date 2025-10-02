#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/water-bottles-ii/

class WaterBottlesII {
public:
    // 0 ms, faster than 100% : 8.42 MB, less than 79.3%
    int solution(int numBottles, int numExchange)
    {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            ans++;
            numBottles -= numExchange++ - 1;
        }

        return ans;
    }
    vector<int> output = {
        15,
        13
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        13,
        10
       
    };
    vector<int> input2 = {
        6,
        3
    };
};