#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/

class MinimumDeletionsToMakeStringBalanced {
public:
    // 75 ms, faster than 91.23% : 23.48 MB, less than 80.38%
    int solution(string s)
    {
        int as = count_if(begin(s), end(s), [](char c) { return c == 'a'; }), bs = 0;
        int ans = INT_MAX;
        for (auto c : s) {
            as -= c == 'a';
            ans = min(ans, as + bs);
            bs += c == 'b';
        }

        return ans;
    }
    vector<int> output = {
        2,
        2
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "aababbab",
        "bbaaaaabb"
    };
};