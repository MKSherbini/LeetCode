#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/get-equal-substrings-within-budget/description/

class GetEqualSubstringsWithinBudget {
public:
    // 4 ms, faster than 85.51% : 8.66 MB, less than 93.85%
    int solution(string s, string t, int maxCost)
    {
        int n = size(s);
        int i = 0;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            maxCost -= abs(s[j] - t[j]);
            while (maxCost < 0) {
                maxCost += abs(s[i] - t[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
    vector<int> output = {
        3,
        1,
        1
    };
    static constexpr int const& inputs = 3;
    vector<string> input1 = {
        "abcd",
        "abcd",
        "abcd"
    };
    vector<string> input2 = {
        "bcdf",
        "cdef",
        "acde"
    };
    vector<int> input3 = {
        3,
        3,
        0
    };
};