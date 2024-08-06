#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/

class MinimumNumberOfPushesToTypeWordII {
public:
    // 61 ms, faster than 95.56% : 24.72 MB, less than 66.15%
    int solution(string word)
    {
        vector<int> f(26);
        for (auto c : word) {
            f[c - 'a']++;
        }
        sort(begin(f), end(f), greater());

        int ans = 0;
        for (size_t i = 0; i < 26; i++) {
            if (!f[i])
                break;

            ans += (i / 8 + 1) * f[i];
        }

        return ans;
    }
    vector<int> output = {
        5,
        12,
        24
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "abcde",
        "xyzxyzxyzxyz",
        "aabbccddeeffgghhiiiiii"
    };
};