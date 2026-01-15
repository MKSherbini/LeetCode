#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid

class MaximizeAreaOfSquareHoleInGrid {
public:
    // 0 ms, faster than 100% : 31.74 MB, less than 99.13%
    int solution(int n, int m, vector<int> hBars, vector<int> vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int mxH = 2;
        int c = 2;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] - hBars[i - 1] <= 1) {
                c++;
            } else {
                c = 2;
            }
            mxH = max(mxH, c);
        }

        int mxV = 2;
        c = 2;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] - vBars[i - 1] <= 1) {
                c++;
            } else {
                c = 2;
            }
            mxV = max(mxV, c);
        }

        return pow(min(mxV, mxH), 2);
    }
    vector<int> output = {
        4,
        4,
        4
    };
    static constexpr int const& inputs = 4;
    vector<int> input1 = {
        2,
        1,
        2
    };
    vector<int> input2 = {
        1,
        1,
        3
    };
    vector<vector<int>> input3 = {
        { 2, 3 },
        { 2 },
        { 2, 3 }
    };
    vector<vector<int>> input4 = {
        { 2 },
        { 2 },
        { 2, 4 }
    };
};