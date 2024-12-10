#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i

class FindLongestSpecialSubstringThatOccursThriceI {
public:
    // 4 ms, faster than 90.8% : 12.14 MB, less than 67.47%
    int solution(string s)
    {
        unordered_map<string, int> m;

        int n = size(s);
        int ans = -1;
        for (size_t i = 0; i < n; i++) {
            string t;
            for (size_t j = i; j < n; j++) {
                if (s[i] != s[j])
                    break;
                t += s[j];
                if (++m[t] >= 3 && (int)size(t) > ans) {
                    ans = size(t);
                }
            }
        }

        return ans;
    }
    vector<int> output = {
        2,
        -1,
        1
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "aaaa",
        "abcdef",
        "abcaba"
    };
};