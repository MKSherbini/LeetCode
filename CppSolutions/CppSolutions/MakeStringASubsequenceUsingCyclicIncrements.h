#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments

class MakeStringASubsequenceUsingCyclicIncrements {
public:
    // 0 ms, faster than 100% : 17.03 MB, less than 14.64%
    uint8_t solution(string str1, string str2)
    {
        int n = size(str1), m = size(str2);
        int j = 0;
        for (size_t i = 0; i < n; i++) {
            if (str1[i] == str2[j] || (str1[i] - 'a' + 1) % 26 + 'a' == str2[j]) {
                j++;
                if (j == m)
                    return 1;
            }
        }

        return 0;
    }
    vector<uint8_t> output = {
        true,
        true,
        false
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "abc",
        "zc",
        "ab"
    };
    vector<string> input2 = {
        "ad",
        "ad",
        "d"
    };
};