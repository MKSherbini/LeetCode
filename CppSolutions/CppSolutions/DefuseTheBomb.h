#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/defuse-the-bomb

class DefuseTheBomb {
public:
    // 0 ms, faster than 100% : 10.25 MB, less than 83.96%
    vector<int> solution(vector<int> code, int k)
    {
        int n = size(code);
        if (k == 0)
            return vector(n, 0);

        int st = 1, en = k;
        if (k < 0) {
            en = n - 1;
            st = n + k;
        }

        int sum = accumulate(begin(code) + st, begin(code) + en + 1, 0);

        vector<int> ans(n);
        for (size_t i = 0; i < n; i++) {
            ans[i] = sum;
            sum -= code[st % n];
            sum += code[(en + 1) % n];
            st++, en++;
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 12, 10, 16, 13 },
        { 0, 0, 0, 0 },
        { 12, 5, 6, 13 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 5, 7, 1, 4 },
        { 1, 2, 3, 4 },
        { 2, 4, 9, 3 }
    };
    vector<int> input2 = {
        3,
        0,
        -2
    };
};