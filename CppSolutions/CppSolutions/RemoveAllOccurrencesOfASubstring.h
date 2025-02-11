#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/remove-all-occurrences-of-a-substring

class RemoveAllOccurrencesOfASubstring {
public:
    // 0 ms, faster than 100% : 9.34 MB, less than 68.3%
    string solution(string s, string part)
    {
        string st;
        auto f = [&]() {
            if (size(st) < size(part))
                return;
            int d = size(st) - size(part);
            for (size_t i = 0; i < size(part); i++) {
                if (st[i + d] != part[i])
                    return;
            }

            st.resize(size(st) - size(part));
        };

        for (size_t i = 0; i < size(s); i++) {
            st.push_back(s[i]);
            f();
        }

        return st;
    }

    // 0 ms, faster than 100% : 10.49 MB, less than 11.34%
    string solution2(string s, string part)
    {
        int it;
        while ((it = s.find(part)) != -1) {
            s = s.substr(0, it) + s.substr(it + size(part));
        }

        return s;
    }
    vector<string> output = {
        "dab",
        "ab"
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "daabcbaabcbc",
        "axxxxyyyyb"
    };
    vector<string> input2 = {
        "abc",
        "xy"
    };
};