#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/

class SplitAStringIntoTheMaxNumberOfUniqueSubstrings {
public:
    // 279 ms, faster than 37.43% : 74.32 MB, less than 32.46%
    int solution(string s)
    {
        int n = size(s);

        size_t ans = 0;
        unordered_set<string> st;
        function<void(int, int)> f = [&](int i, int len) -> void {
            Printer::print(i, len);
            if (i + len > n)
                return;

            f(i, len + 1);

            string t = s.substr(i, len);
            if (st.count(t))
                return;

            st.insert(t);
            f(i + len, 1);
            if (i + len == n) {
                ans = max(ans, size(st));
                Printer::print(st);
            }
            st.erase(t);
        };

        f(0, 1);

        return ans;
    }
    vector<int> output = {
        5,
        2,
        1
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "ababccc",
        "aba",
        "aa"
    };
};