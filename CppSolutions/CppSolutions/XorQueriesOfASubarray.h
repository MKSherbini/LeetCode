#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/xor-queries-of-a-subarray/description/

class XorQueriesOfASubarray {
public:
    // 45 ms, faster than 93.91% : 41.35 MB, less than 96.52%
    vector<int> solution(vector<int> arr, vector<vector<int>> queries)
    {
        vector<int> pre(size(arr));
        pre[0] = arr[0];
        for (size_t i = 1; i < size(arr); i++) {
            pre[i] = pre[i - 1] ^ arr[i];
        }

        vector<int> ans(size(queries));
        for (size_t i = 0; i < size(queries); i++) {
            ans[i] = (queries[i][0] > 0 ? pre[queries[i][0] - 1] : 0) ^ pre[queries[i][1]];
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 2, 7, 14, 8 },
        { 8, 0, 4, 4 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 3, 4, 8 },
        { 4, 8, 2, 10 }
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 1 }, { 1, 2 }, { 0, 3 }, { 3, 3 } },
        { { 2, 3 }, { 1, 3 }, { 0, 0 }, { 0, 3 } }
    };
};