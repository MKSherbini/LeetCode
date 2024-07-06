#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/pass-the-pillow/description/

class PassThePillow {
public:
    // 0 ms, faster than 100% : 7.01 MB, less than 71.18%
    int solution(int n, int time)
    {
        int cycle = (n - 1) * 2;
        time %= cycle;

        return time < n ? time + 1 : cycle - time + 1;
    }
    vector<int> output = {
        2,
        3
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        4,
        3
    };
    vector<int> input2 = {
        5,
        2
    };
};