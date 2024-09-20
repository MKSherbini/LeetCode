#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/shortest-palindrome/description/

class ShortestPalindrome {
public:
    // 43 ms, faster than 6.55% : 716.04 MB, less than 5.09%
    string solution(string s)
    {
        // abca
        // acba

        string r(s.rbegin(), s.rend());
        for (size_t i = 0; i < size(r); i++) {
            if (s.starts_with(r.substr(i)))
                return r.substr(0, i) + s;
        }

        return r + s;
    }
    vector<string> output = {
        "aaacecaaa",
        "dcbabcd"
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "aacecaaa",
        "abcd"
    };
};