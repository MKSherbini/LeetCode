#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/plus-one

class PlusOne {
public:
    // 0 ms, faster than 100% : 11.39 MB, less than 92.86%
    vector<int> solution(vector<int> digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
    vector<vector<int>> output = {
        { 1, 2, 4 },
        { 4, 3, 2, 2 },
        { 1, 0 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 3 },
        { 4, 3, 2, 1 },
        { 9 }
    };
};