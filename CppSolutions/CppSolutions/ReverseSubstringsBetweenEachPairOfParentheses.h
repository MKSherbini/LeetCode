#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/

class ReverseSubstringsBetweenEachPairOfParentheses {
public:
    // 0 ms, faster than 100% : 7.74 MB, less than 52.67%
    string solution(string s)
    {
        stack<int> st;
        for (size_t i = 0; i < size(s); i++) {
            if (s[i] == '(')
                st.push(i);
            if (s[i] == ')')
                reverse(begin(s) + st.top(), begin(s) + i + 1), st.pop();
        }

        string ans;
        for (size_t i = 0; i < size(s); i++) {
            if (s[i] == ')' || s[i] == '(')
                continue;
            ans.push_back(s[i]);
        }

        return ans;
    }
    vector<string> output = {
        "dcba",
        "iloveu",
        "leetcode"
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "(abcd)",
        "(u(love)i)",
        "(ed(et(oc))el)"
    };
};