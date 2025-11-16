#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/number-of-substrings-with-only-1s

class NumberOfSubstringsWithOnly1s {
public:
    // 0 ms, faster than 100% : 11.42 MB, less than 95.37%
    long long solution(string s)
    {
        const int MOD = 1e9 + 7;
        long long cnt = 0;
        long long ans = 0;
        for (char c : s) {
            if (c == '1') {
                cnt++;
                ans += cnt;
                ans %= MOD;
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
    vector<int> output = {
        9,
        2,
        21
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "0110111",
        "101",
        "111111"
    };
};