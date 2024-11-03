#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/rotate-string

class RotateString {
public:
    // 0 ms, faster than 100% : 7.46 MB, less than 94.35%
    uint8_t solution(string s, string goal)
    {
        return size(s) == size(goal) && (s + s).find(goal) != string::npos;
    }
    vector<uint8_t> output = {
        true,
        false
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "abcde",
        "abcde"
    };
    vector<string> input2 = {
        "cdeab",
        "abced"
    };
};