#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/clear-digits

class ClearDigits {
public:
    // 0 ms, faster than 100% : 8.28 MB, less than 96.37%
    string solution(string s)
    {
        int n = size(s);
        int d = 0;

       for (int i = n - 1; i >= 0 ; i--) {
            if (isdigit(s[i]))
                d++, s[i] = '/';
            else if (d)
                d--, s[i] = '/';
        }

         for (size_t i = 0; i < n && d; i++) {
            if (s[i] != '/')
                d--, s[i] = '/';
        }

        string ans;
        for (size_t i = 0; i < n; i++) {
            if (s[i] != '/')
                ans.push_back(s[i]);
        }

        return ans;
    }
    vector<string> output = {
        "abc",
        ""
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "abc",
        "cb34"
    };
};