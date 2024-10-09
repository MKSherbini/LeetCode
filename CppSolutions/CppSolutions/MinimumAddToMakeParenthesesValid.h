#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

class MinimumAddToMakeParenthesesValid {
public:
    // 0 ms, faster than 100% : 7.53 MB, less than 99.04%
    int solution(string s)
    {
        int cnt = 0, ans = 0;
        for (auto c : s) {
            if (c == '(')
                cnt++;
            else if (cnt > 0)
                cnt--;
            else
                ans++;
        }

        return cnt + ans;
    }
    vector<int> output = {
        1,
        3
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "())",
        "((("
    };
};