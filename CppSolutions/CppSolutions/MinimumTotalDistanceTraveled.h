#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-total-distance-traveled

class MinimumTotalDistanceTraveled {
public:
    // 2381 ms, faster than 6.9% : 69.48 MB, less than 7.5%
    int solution(vector<int> robot, vector<vector<int>> factory)
    {
        sort(begin(robot), end(robot), [](const auto& a, const auto& b) {
            return a < b;
        });
        sort(begin(factory), end(factory), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        vector<int> factorPos;
        for (auto& f : factory)
            for (size_t i = 0; i < f[1]; i++)
                factorPos.push_back(f[0]);

        int n = size(robot), m = size(factorPos);
        vector mem(n, vector(m, -1LL));
        function<long long(int, int)> f = [&](int i, int j) -> long long {
            if (i == n)
                return 0;

            if (j == m)
                return 1e16;

            if (mem[i][j] != -1)
                return mem[i][j];

            return mem[i][j] = min(f(i, j + 1), f(i + 1, j + 1) + abs(robot[i] - factorPos[j]));
        };

        f(0, 0);
        Printer::print(mem);

        return f(0, 0);
    }
    vector<int> output = {
        4,
        2,
        6
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 0, 4, 6 },
        { 1, -1 },
        { 9, 11, 99, 101 }
    };
    vector<vector<vector<int>>> input2 = {
        { { 2, 2 }, { 6, 2 } },
        { { -2, 1 }, { 2, 1 } },
        { { 10, 1 }, { 7, 1 }, { 14, 1 }, { 100, 1 }, { 96, 1 }, { 103, 1 } }
    };
};