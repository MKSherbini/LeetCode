#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers

class ConvertIntegerToTheSumOfTwoNoZeroIntegers {
public:
    // 0 ms, faster than 100% : 8.02 MB, less than 98.8%
    vector<int> solution(int n)
    {
        auto noZero = [](int x) {
            while (x) {
                if (x % 10 == 0)
                    return false;
                x /= 10;
            }
            return true;
        };
        for (int i = 1; i < n; ++i) {
            int a = i;
            int b = n - i;
            if (noZero(a) && noZero(b))
                return { a, b };
        }

        return {};
    }
    vector<vector<int>> output = {
        { 1, 1 },
        { 2, 9 }
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        2,
        11
    };
};