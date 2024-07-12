#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-score-from-removing-substrings/description/

class MaximumScoreFromRemovingSubstrings {
public:
    // 63 ms, faster than 87.81% : 24.07 MB, less than 49.59%
    int solution(string s, int x, int y)
    {
        vector<char> st;
        int ans = 0;
        char first = x > y ? 'a' : 'b', second = x > y ? 'b' : 'a';
        for (auto c : s) {
            if (c != 'a' && c != 'b')
                st.push_back(c);

            if (!empty(st) && st.back() == first && c == second)
                st.pop_back(), ans += max(x, y);
            else
                st.push_back(c);
        }

        int c = 0;
        for (size_t i = 0; i < size(st); i++) {
            if (st[i] == second)
                c++;
            else if (c > 0 && st[i] == first)
                c--, ans += min(x, y);
            else
                c = 0;
        }

        return ans;
    }
    vector<int> output = {
        19,
        20
    };
    static constexpr int const& inputs = 3;
    vector<string> input1 = {
        "cdbcbbaaabab",
        "aabbaaxybbaabb"
    };
    vector<int> input2 = {
        4,
        5
    };
    vector<int> input3 = {
        5,
        4
    };
};