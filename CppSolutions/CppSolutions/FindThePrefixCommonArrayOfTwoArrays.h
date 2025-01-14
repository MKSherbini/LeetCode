#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays

class FindThePrefixCommonArrayOfTwoArrays {
public:
    // 0 ms, faster than 100% : 85.61 MB, less than 92.22%
    vector<int> solution(vector<int> A, vector<int> B)
    {
        int n = size(A);
        vector<int> v(n), ans(n);

        int c = 0;
        for (size_t i = 0; i < size(A); i++) {
            if (++v[A[i] - 1] == 2)
                c++;
            if (++v[B[i] - 1] == 2)
                c++;

            ans[i] = c;
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 0, 2, 3, 4 },
        { 0, 1, 3 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 3, 2, 4 },
        { 2, 3, 1 }
    };
    vector<vector<int>> input2 = {
        { 3, 1, 2, 4 },
        { 3, 1, 2 }
    };
};