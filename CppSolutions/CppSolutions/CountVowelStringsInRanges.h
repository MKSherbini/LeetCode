#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-vowel-strings-in-ranges

class CountVowelStringsInRanges {
public:
    // 2 ms, faster than 91.64% : 69.21 MB, less than 74.2%
    vector<int> solution(vector<string> words, vector<vector<int>> queries)
    {
        int n = size(words), m = size(queries);
        vector<int> pre(n);
        string vowels = "aeiou";
        for (size_t i = 0; i < n; i++) {
            pre[i] = vowels.find(words[i][0]) != -1 && vowels.find(words[i].back()) != -1;
            if (i > 0)
                pre[i] += pre[i - 1];
        }

        vector<int> ans(m);
        for (size_t i = 0; i < m; i++) {
            ans[i] = pre[queries[i][1]] - (queries[i][0] > 0 ? pre[queries[i][0] - 1] : 0);
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 2, 3, 0 },
        { 3, 2, 1 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<string>> input1 = {
        { "aba", "bcb", "ece", "aa", "e" },
        { "a", "e", "i" }
    };
    vector<vector<vector<int>>> input2 = {
        { { 0, 2 }, { 1, 4 }, { 1, 1 } },
        { { 0, 2 }, { 0, 1 }, { 2, 2 } }
    };
};