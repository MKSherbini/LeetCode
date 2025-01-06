#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box

class MinimumNumberOfOperationsToMoveAllBallsToEachBox {
public:
    // 0 ms, faster than 100% : 11.95 MB, less than 76.52%
    vector<int> solution(string boxes)
    {
        int n = size(boxes);
        vector<int> ans(n);
        int b = 0, steps = 0;
        for (size_t i = 0; i < n; i++) {
            ans[i] += steps;
            b += boxes[i] == '1';
            steps += b;
        }

        b = 0, steps = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += steps;
            b += boxes[i] == '1';
            steps += b;
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 1, 1, 3 },
        { 11, 8, 5, 4, 3, 4 }
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "110",
        "001011"
    };
};