#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i

class CheckIfDigitsAreEqualInStringAfterOperationsI {
public:
    // 0 ms, faster than 100% : 8.23 MB, less than 98.68%
    uint8_t solution(string s)
    {
        int n = s.size();
        for (int len = n - 1; len >= 2; len--) {
            for (int i = 0; i < len; i++) {
                s[i] = (s[i] + s[i + 1] - '0' - '0') % 10 + '0';
            }
            Printer::print(s);
        }
        return s[0] == s[1];
    }
    vector<uint8_t> output = {
        true,
        false
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "3902",
        "34789"
    };
};