#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end

class MaximumNumberOfOperationsToMoveOnesToTheEnd {
public:
    // 0 ms, faster than 100% : 15.68 MB, less than 85.14%
    int solution(string s)
    {
        int n = s.size();
        int ans = 0, ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            } else {
                ans += ones;
                while (i < n && s[i] == '0') {
                    i++;
                }
                i--;
            }
        }

        return ans;
    }
    vector<int> output = {
        4,
        0
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "1001101",
        "00111"
    };
};