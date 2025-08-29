#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/alice-and-bob-playing-flower-game

class AliceAndBobPlayingFlowerGame {
public:
    // 0 ms, faster than 100% : 8.38 MB, less than 86.22%
    long long solution(int n, int m)
    {
        return ((n + 1LL) / 2 * (m / 2)) + ((m + 1LL) / 2 * (n / 2));
    }
    vector<int> output = {
        3,
        0
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        3,
        1
    };
    vector<int> input2 = {
        2,
        1
    };
};