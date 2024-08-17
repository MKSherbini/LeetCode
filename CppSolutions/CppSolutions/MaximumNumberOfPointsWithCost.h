#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-number-of-points-with-cost/description/

class MaximumNumberOfPointsWithCost {
public:
    // 208 ms, faster than 43.87% : 128.95 MB, less than 37.33%
    int solution(vector<vector<int>> points)
    {
        int n = size(points), m = size(points[0]);
        vector lastRow(m, 0LL);
        for (size_t j = 0; j < m; j++) {
            lastRow[j] = points[0][j];
        }

        for (size_t i = 1; i < n; i++) {
            vector<long long> leftMax(m);
            vector<long long> rightMax(m);
            vector<long long> currentRow(m);

            leftMax[0] = lastRow[0];
            for (int col = 1; col < m; ++col) {
                leftMax[col] = max(leftMax[col - 1] - 1, lastRow[col]);
            }

            rightMax[m - 1] = lastRow[m - 1];
            for (int col = m - 2; col >= 0; --col) {
                rightMax[col] = max(rightMax[col + 1] - 1, lastRow[col]);
            }

            for (int col = 0; col < m; ++col) {
                currentRow[col] = points[i][col] + max(leftMax[col], rightMax[col]);
            }

            lastRow = currentRow;
        }

        return *max_element(begin(lastRow), end(lastRow));
    }

    // TLE
    int solution2(vector<vector<int>> points)
    {
        int n = size(points), m = size(points[0]);
        vector mem(n, vector(m, -1LL));
        function<int(int, int)> f = [&](int i, int lastJ) -> int {
            if (i == n)
                return 0;
            if (lastJ != -1 && mem[i][lastJ] != -1)
                return mem[i][lastJ];

            long long ret = 0;
            for (int j = 0; j < m; j++) {
                ret = max(ret, (long long)points[i][j] + f(i + 1, j) - (lastJ == -1 ? 0 : abs(lastJ - j)));
            }

            if (lastJ != -1)
                mem[i][lastJ] = ret;
            return ret;
        };

        return f(0, -1);
    }
    vector<int> output = {
        9,
        11
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2, 3 }, { 1, 5, 1 }, { 3, 1, 1 } },
        { { 1, 5 }, { 2, 3 }, { 4, 2 } }
    };
};