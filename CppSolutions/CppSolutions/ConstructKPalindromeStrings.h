#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/construct-k-palindrome-strings

class ConstructKPalindromeStrings {
public:
    // 0 ms, faster than 100% : 14.81 MB, less than 66.78%
    uint8_t solution(string s, int k)
    {
        int odds = 0, evens = 0;
        vector<int> f(26);
        for (auto c : s) {
            f[c - 'a']++;
        }

        for (size_t i = 0; i < 26; i++) {
            odds += f[i] % 2 == 1;
            evens += f[i] / 2;
        }

        Printer::print(odds, evens);

        if (odds > k)
            return false;

        if (odds + evens * 2 < k)
            return false;

        return true;
    }
    vector<uint8_t> output = {
        true,
        false,
        true,
        true,
        true
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "annabelle",
        "leetcode",
        "true",
        "qlkzenwmmnpkopu",
        "ibzkwaxxaggkiwjbeysz"
    };
    vector<int> input2 = {
        2,
        3,
        4,
        15,
        15
    };
};