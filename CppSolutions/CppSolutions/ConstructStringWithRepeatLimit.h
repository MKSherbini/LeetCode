#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/construct-string-with-repeat-limit

class ConstructStringWithRepeatLimit {
public:
    // 45 ms, faster than 50.89% : 27.8 MB, less than 52.21%
    string solution(string s, int repeatLimit)
    {
        map<char, int> m;
        for (auto c : s)
            m[c]++;

        string ans;
        while (!empty(m)) {
            for (size_t i = 0; i < min(repeatLimit, m.rbegin()->second); i++) {
                ans += m.rbegin()->first;
            }
            m.rbegin()->second -= repeatLimit;
            if (m.rbegin()->second <= 0) {
                m.erase(m.rbegin()->first);
            } else {
                if (size(m) == 1) {
                    break;
                } else {
                    ans += next(m.rbegin())->first;
                    next(m.rbegin())->second--;
                    if (next(m.rbegin())->second <= 0) {
                        m.erase(next(m.rbegin())->first);
                    }
                }
            }
        }

        return ans;
    }
    vector<string> output = {
        "zzcccac",
        "bbabaa"
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "cczazcc",
        "aababab"
    };
    vector<int> input2 = {
        3,
        2
    };
};