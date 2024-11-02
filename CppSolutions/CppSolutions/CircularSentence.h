#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/circular-sentence

class CircularSentence {
public:
    // 0 ms, faster than 100% : 8.13 MB, less than 83.91%
    uint8_t solution(string sentence)
    {
        for (size_t i = 0; i < size(sentence); i++) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
                return 0;
        }

        return sentence[0] == sentence.back();
    }
    vector<uint8_t> output = {
        true,
        true,
        false
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "leetcodeexercisessounddelightful",
        "eetcode",
        "Leetcodeiscool"
    };
};