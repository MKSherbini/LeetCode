#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/string-compression-iii

class StringCompressionIII {
public:
    // 20 ms, faster than 78.63% : 29.74 MB, less than 57.63%
    string solution(string word)
    {
        string ans;
        char lastC = 'X';
        int cnt = 0;
        for (auto c : word) {
            if (cnt == 0) {
                lastC = c;
                cnt++;
                continue;
            }

            if (lastC == c) {
                cnt++;

                if (cnt == 9) {
                    cnt = 0;
                    ans += "9";
                    ans += c;
                }
            } else {
                ans += to_string(cnt);
                ans += lastC;
                cnt = 1;
                lastC = c;
            }
        }

        if (cnt) {
            ans += to_string(cnt);
            ans += lastC;
        }

        return ans;
    }
    vector<string> output = {
        "1a1b1c1d1e",
        "9a5a2b"
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "abcde",
        "aaaaaaaaaaaaaabb"
    };
};