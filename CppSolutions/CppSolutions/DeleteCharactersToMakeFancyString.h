#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/delete-characters-to-make-fancy-string

class DeleteCharactersToMakeFancyString {
public:
    // 15 ms, faster than 93.51% : 42.75 MB, less than 63.26%
    string solution(string s)
    {
        string ans;
        for (auto c : s) {
            if (size(ans) >= 2 && ans.back() == c && ans[size(ans) - 2] == c)
                continue;

            ans.push_back(c);
        }

        return ans;
    }
    vector<string> output = {
        "leetcode",
        "aabaa",
        "aab"
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "leeetcode",
        "aaabaaaa",
        "aab"
    };
};