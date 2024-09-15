#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/

class FindTheLongestSubstringContainingVowelsInEvenCounts {
public:
    // 91 ms, faster than 24.19% : 18.88 MB, less than 51.86%
    int solution(string s)
    {
        int n = size(s);
        unordered_map<char, int> m = { { 'a', 1 }, { 'e', 2 }, { 'i', 4 }, { 'o', 8 }, { 'u', 16 } };
        unordered_map<int, int> codes;
        int ans = 0, code = 0;

        codes[0] = -1;
        for (int i = 0; i < n; i++) {
            if (m.count(s[i])) {
                code ^= m[s[i]];
            }

            if (!codes.count(code))
                codes[code] = i;
            else
                ans = max(ans, i - codes[code]);

            Printer::print(i, s[i], code);
        }

        return ans;
    }
    vector<int> output = {
        13,
        5,
        6,
        8
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "eleetminicoworoep",
        "leetcodeisgreat",
        "bcbcbc",
        "amntyyaw"
    };
};