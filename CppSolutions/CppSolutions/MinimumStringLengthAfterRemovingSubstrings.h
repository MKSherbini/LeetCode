#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/

class MinimumStringLengthAfterRemovingSubstrings {
public:
    // 3 ms, faster than 89.69% : 11.54 MB, less than 55.74%
    int solution(string s)
    {
        int n = size(s);
        int i = 0, j = 1;

        int ans = n;
        stack<char> st;
        for (size_t i = 0; i < n; i++) {
            if (!empty(st) && ((st.top() == 'A' && s[i] == 'B') || (st.top() == 'C' && s[i] == 'D'))) {
                st.pop();
                ans -= 2;
            } else {
                st.push(s[i]);
            }
        }

        return ans;
    }
    vector<int> output = {
        2,
        5
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "ABFCACDB",
        "ACBBD"
    };
};