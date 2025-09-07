#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class FindNUniqueIntegersSumUpToZero {
public:
    // 0 ms, faster than 100% : 9.48 MB, less than 98.77%
    vector<int> solution(int n)
    {
        vector<int> ans;
        if (n % 2 == 1)
            ans.push_back(0);
        for (int i = 1; i <= n / 2; ++i) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
    vector<vector<int>> output = {
        { -7, -1, 1, 3, 4 },
        { -1, 0, 1 },
        { 0 }
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        5,
        3,
        1
    };
};