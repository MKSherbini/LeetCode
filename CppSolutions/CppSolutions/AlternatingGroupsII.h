#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/alternating-groups-ii

class AlternatingGroupsII {
public:
    // 54 ms, faster than 97.47% : 102.58 MB, less than 91.98%
    int solution(vector<int> colors, int k)
    {
        int n = colors.size();
        int lastEq = 0;
        int ans = 0;
        for (size_t i = 1; i < n + k - 1; i++) {
            if (colors[i % n] == colors[(i + n - 1) % n]) {
                lastEq = i;
            }

            Printer::print(i, lastEq, i - lastEq + 1, i - lastEq + 1 >= k);
            if (i - lastEq + 1 >= k)
                ans++;
        }

        return ans;
    }
    vector<int> output = {
        3,
        2,
        0
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 0, 1, 0, 1, 0 },
        { 0, 1, 0, 0, 1, 0, 1 },
        { 1, 1, 0, 1 }
    };
    vector<int> input2 = {
        3,
        6,
        4
    };
};