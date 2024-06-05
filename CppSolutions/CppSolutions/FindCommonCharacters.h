#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-common-characters/description/

class FindCommonCharacters {
public:
    // 3 ms, faster than 96.29% : 12.05 MB, less than 31.97%
    vector<string> solution(vector<string> words)
    {
        vector f(26, 200);
        for (auto w : words) {
            vector t(26, 0);
            for (auto c : w) {
                t[c - 'a']++;
            }
            for (size_t i = 0; i < 26; i++) {
                f[i] = min(f[i], t[i]);
            }
        }

        vector<string> ans;
        for (size_t i = 0; i < 26; i++) {
            fill_n(back_inserter(ans), f[i], string(1, 'a' + i));
        }

        return ans;
    }
    vector<vector<string>> output = {
        { "e", "l", "l" },
        { "c", "o" }
    };
    static constexpr int const& inputs = 1;
    vector<vector<string>> input1 = {
        { "bella", "label", "roller" },
        { "cool", "lock", "cook" }
    };
};