#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/counting-words-with-a-given-prefix

class CountingWordsWithAGivenPrefix {
public:
    // 0 ms, faster than 100% : 12.85 MB, less than 98.98%
    int solution(vector<string> words, string pref)
    {
        int n = size(words);
        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            if (words[i].starts_with(pref)) {
                ans++;
            }
        }

        return ans;
    }
    vector<int> output = {
        2,
        0
    };
    static constexpr int const& inputs = 2;
    vector<vector<string>> input1 = {
        { "pay", "attention", "practice", "attend" },
        { "leetcode", "win", "loops", "success" }
    };
    vector<string> input2 = {
        "at",
        "code"
    };
};