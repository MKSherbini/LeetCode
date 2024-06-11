#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/relative-sort-array/description/

class RelativeSortArray {
public:
    // 0 ms, faster than 100% : 9.22 MB, less than 98.03%
    vector<int> solution(vector<int> arr1, vector<int> arr2)
    {
        int n = size(arr1);
        vector f(1001, 0);
        for (auto x : arr1)
            f[x]++;

        int i = 0;
        vector<int> ans(n);
        for (auto x : arr2) {
            for (size_t j = 0; j < f[x]; j++) {
                ans[i++] = x;
            }
            f[x] = 0;
        }

        for (size_t j = 0; j < 1001; j++) {
            for (size_t k = 0; k < f[j]; k++) {
                ans[i++] = j;
            }
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19 },
        { 22, 28, 8, 6, 17, 44 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 },
        { 28, 6, 22, 8, 44, 17 }
    };
    vector<vector<int>> input2 = {
        { 2, 1, 4, 3, 9, 6 },
        { 22, 28, 8, 6 }
    };
};