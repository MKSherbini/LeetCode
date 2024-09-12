#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-the-number-of-consistent-strings/description/

class CountTheNumberOfConsistentStrings {
public:
    // 31 ms, faster than 97.78% : 33.66 MB, less than 99.35%
    int solution(string allowed, vector<string> words)
    {
        auto f = [&](string& s) {
            bitset<26> bs;
            for (auto c : s)
                bs.set(c - 'a');
            return bs;
        };

        auto mask = ~f(allowed);
        int ans = 0;
        for (auto& w : words) {
            auto bs = f(w);
            bs &= mask;
            if (bs == 0)
                ans++;
        }

        return ans;
    }
    vector<int> output = {
        2,
        7,
        4
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "ab",
        "abc",
        "cad"
    };
    vector<vector<string>> input2 = {
        { "ad", "bd", "aaab", "baa", "badab" },
        { "a", "b", "c", "ab", "ac", "bc", "abc" },
        { "cc", "acd", "b", "ba", "bac", "bad", "ac", "d" }
    };
};