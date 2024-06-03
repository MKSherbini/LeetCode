#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/

class AppendCharactersToStringToMakeSubsequence {
public:
    // 14 ms, faster than 89.29% : 11.82 MB, less than 83.42%
    int solution(string s, string t)
    {
        int i = 0;
        for (auto x : s)
            if (x == t[i]) {
                i++;
                if (i == size(t))
                    break;
            }

        return size(t) - i;
    }
    vector<int> output = {
        4,
        0,
        5
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "coaching",
        "abcde",
        "z"
    };
    vector<string> input2 = {
        "coding",
        "a",
        "abcde"
    };
};