#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/average-waiting-time/

class AverageWaitingTime {
public:
    // 129 ms, faster than 97.35% : 76.28 MB, less than 100%
    double solution(vector<vector<int>> customers)
    {
        int nextStart = 0;
        long long waits = 0;
        for (auto& c : customers) {
            if (nextStart < c[0])
                nextStart = c[0];
            waits += nextStart - c[0] + c[1];
            nextStart += c[1];
        }

        return 1.0 * waits / size(customers);
    }
    vector<double> output = {
        5.00000,
        3.25000
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2 }, { 2, 5 }, { 4, 3 } },
        { { 5, 2 }, { 5, 4 }, { 10, 3 }, { 20, 1 } }
    };
};