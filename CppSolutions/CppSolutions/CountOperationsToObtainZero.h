#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-operations-to-obtain-zero

class CountOperationsToObtainZero {
public:
    // 0 ms, faster than 100% : 7.81 MB, less than 71.74%
    int solution(int num1, int num2)
    {
        int ans = 0;
        while (num1 > 0 && num2 > 0) {
            if (num1 >= num2) {
                num1 -= num2;
            }
            else {
                num2 -= num1;
            }
            ans++;
        }
        return ans;
    }
    vector<int> output = {
        3,
        1
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        2,
        10
    };
    vector<int> input2 = {
        3,
        10
    };
};