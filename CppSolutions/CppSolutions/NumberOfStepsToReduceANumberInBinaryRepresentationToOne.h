#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/

class NumberOfStepsToReduceANumberInBinaryRepresentationToOne {
public:
    // 0 ms, faster than 100% : 7.36 MB, less than 93.86%
    int solution(string s)
    {
        int n = size(s);
        int ans = 0, c = 0;
        for (int i = n - 1; i > 0; i--) {
            int cur = (s[i] == '1') + c;
            c = 0;
            if (cur == 0)
                ans += 1;
            else if (cur == 1)
                ans += 2, c = 1;
            else
                ans += 1, c = 1;
        }

        return ans + c;
    }
    vector<int> output = {
        6,
        1,
        0
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "1101",
        "10",
        "1"
    };
};