#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/string-matching-in-an-array

class StringMatchingInAnArray {
public:
    // 0 ms, faster than 100% : 11.2 MB, less than 78.48%
    vector<string> solution(vector<string> words)
    {
        vector<string> ans;
        int n = size(words);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                if (i == j)
                    continue;
                
                if (words[j].find(words[i])!=-1) {
                    ans.push_back(words[i]);
                    break;
                }

            }
        }

        return ans;
    }
    vector<vector<string>> output = {
        { "as", "hero" },
        { "et", "code" },
        {}
    };
    static constexpr int const& inputs = 1;
    vector<vector<string>> input1 = {
        { "mass", "as", "hero", "superhero" },
        { "leetcode", "et", "code" },
        { "blue", "green", "bu" }
    };
};