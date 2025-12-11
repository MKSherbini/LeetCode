#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-covered-buildings

class CountCoveredBuildings {
public:
    // 351 ms, faster than 66.3% : 354.34 MB, less than 66.85%
    int solution(int n, vector<vector<int>> buildings)
    {
        unordered_map<int, int> xmn, xmx, ymx, ymn;
        for (auto& b : buildings) {
            if (!xmn.count(b[1])) {
                xmn[b[1]] = b[0];
                xmx[b[1]] = b[0];
            } else {
                xmn[b[1]] = min(xmn[b[1]], b[0]);
                xmx[b[1]] = max(xmx[b[1]], b[0]);
            }

            if (!ymn.count(b[0])) {
                ymn[b[0]] = b[1];
                ymx[b[0]] = b[1];
            } else {
                ymn[b[0]] = min(ymn[b[0]], b[1]);
                ymx[b[0]] = max(ymx[b[0]], b[1]);
            }
        }

        Printer::print(xmn, xmx, ymn, ymx);
        int ans = 0;
        for (auto& b : buildings) {
            if ((xmn[b[1]] < b[0] && xmx[b[1]] > b[0])
                && (ymn[b[0]] < b[1] && ymx[b[0]] > b[1])) {
                ans++;
            }
        }

        return ans;
    }
    vector<int> output = {
        1,
        0,
        1
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        3,
        3,
        5
    };
    vector<vector<vector<int>>> input2 = {
        { { 1, 2 }, { 2, 2 }, { 3, 2 }, { 2, 1 }, { 2, 3 } },
        { { 1, 1 }, { 1, 2 }, { 2, 1 }, { 2, 2 } },
        { { 1, 3 }, { 3, 2 }, { 3, 3 }, { 3, 5 }, { 5, 3 } }
    };
};