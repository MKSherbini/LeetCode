#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/shifting-letters-ii

class ShiftingLettersII {
public:
    // 0 ms, faster than 100% : 97.68 MB, less than 84.02%
    string solution(string s, vector<vector<int>> shifts)
    {
        int n = size(s);
        vector<int> pre(n);
        for (auto& x : shifts) {
            pre[x[0]] += x[2] == 1 ? 1 : -1;
            if (x[1] + 1 < n)
                pre[x[1] + 1] -= x[2] == 1 ? 1 : -1;
        }

        int acc = 0;
        for (size_t i = 0; i < n; i++) {
            acc += pre[i];
            s[i] = ((s[i] - 'a' + acc) % 26 + 26) % 26 + 'a';
        }

        return s;
    }
    vector<string> output = {
        "ace",
        "catz"
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "abc",
        "dztz"
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 1, 0 }, { 1, 2, 1 }, { 0, 2, 1 } },
        { { 0, 0, 0 }, { 1, 1, 1 } }
    };
};