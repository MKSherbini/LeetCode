#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/

class SumOfDigitsOfStringAfterConvert {
public:
    // 0 ms, faster than 100% : 10.11 MB, less than 21.06%
    int solution(string s, int k)
    {
        string t;
        for (auto c : s)
            t += to_string(c - 'a' + 1);
        s = t;

        while (k--) {
            int sum = 0;
            for (auto c : s)
                sum += c - '0';
            s = to_string(sum);
            Printer::print(s);
        }
        return stoi(s);
    }
    vector<int> output = {
        36,
        6,
        8
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "iiii",
        "leetcode",
        "zbax"
    };
    vector<int> input2 = {
        1,
        2,
        2
    };
};