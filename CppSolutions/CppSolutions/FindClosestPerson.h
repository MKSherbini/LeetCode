#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-closest-person

class FindClosestPerson {
public:
    // 0 ms, faster than 100% : 8.46 MB, less than 88.8%
    int solution(int x, int y, int z)
    {
        return abs(x - z) < abs(y - z) ? 1 : abs(x - z) > abs(y - z) ? 2
                                                                     : 0;
    }
    vector<int> output = {
        1,
        2,
        0
    };
    static constexpr int const& inputs = 3;
    vector<int> input1 = {
        2,
        2,
        1
    };
    vector<int> input2 = {
        7,
        5,
        5
    };
    vector<int> input3 = {
        4,
        6,
        3
    };
};