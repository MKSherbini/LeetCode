#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i

class CountPrefixAndSuffixPairsI {
public:
    // 0 ms, faster than 100% : 23.22 MB, less than 97.46%
    int solution(vector<string> words)
    {
        int n = size(words);
        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i + 1; j < n; j++) {
                if (words[j].starts_with(words[i]) && words[j].ends_with(words[i])) {
                    ans++;
                }
            }
        }

        return ans;
    }
    vector<int> output = {
        4,
        2,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<string>> input1 = {
        { "a", "aba", "ababa", "aa" },
        { "pa", "papa", "ma", "mama" },
        { "abab", "ab" }
    };
};