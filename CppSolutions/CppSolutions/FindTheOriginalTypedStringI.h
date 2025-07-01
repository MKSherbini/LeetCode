#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-original-typed-string-i

class FindTheOriginalTypedStringI {
public:
    // 0 ms, faster than 100% : 8.7 MB, less than 96.34%
    int solution(string word)
    {
        int n = word.size();
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                ans++;
            }
        }
        return ans;
    }
    vector<int> output = {
        5,
        1,
        4
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "abbcccc",
        "abcd",
        "aaaa"
    };
};