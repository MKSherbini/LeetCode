#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/convert-1d-array-into-2d-array/description/

class Convert1dArrayInto2dArray {
public:
    // 63 ms, faster than 97.93% : 87.9 MB, less than 89.37%
    vector<vector<int>> solution(vector<int> original, int m, int n)
    {
        if (m * n != size(original))
            return {};

        vector ans(m, vector(n, 0));

        int it = 0, i = 0, j = 0;
        while (it < size(original)) {
            ans[i][j] = original[it];
            it++;
            j++;
            if (j == n)
                j = 0, i++;
        }

        return ans;
    }
    vector<vector<vector<int>>> output = {
        { { 1, 2 }, { 3, 4 } },
        { { 1, 2, 3 } },
        {}
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 4 },
        { 1, 2, 3 },
        { 1, 2 }
    };
    vector<int> input2 = {
        2,
        1,
        1
    };
    vector<int> input3 = {
        2,
        3,
        1
    };
};