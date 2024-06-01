#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/score-of-a-string/description/

class ScoreOfAString {
public:
    // 0 ms, faster than 100% : 7.73 MB, less than 78.98%
    int solution(string s)
    {
        int n = size(s);
        int ans = 0;
        for (size_t i = 1; i < n; i++) {
            ans += abs(s[i] - s[i - 1]);
        }

        return ans;
    }

    vector<int> output = {
        13,
        50
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "hello",
        "zaz"
    };
};