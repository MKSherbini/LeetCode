#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-deletions-to-make-string-k-special

class MinimumDeletionsToMakeStringKSpecial {
public:
    // 3 ms, faster than 83.49% : 19.23 MB, less than 84.11%
    int solution(string word, int k)
    {
        int n = word.size();
        vector<int> f(26, 0);
        for (char c : word) {
            f[c - 'a']++;
        }
        sort(f.begin(), f.end());

        int st = 0;
        for (; st < 26; st++) {
            if (f[st] != 0) {
                break;
            }
        }
        if (st == 26) {
            return 0;
        }

        int ans = INT_MAX;
        for (int i = st; i < 26; ++i) {
            Printer::print(i, f[i]);

            int t = 0;
            for (int j = i; j < 26; j++) {
                if (f[j] > f[i] + k) {
                    t += f[i] + k;
                } else {
                    t += f[j];
                }
            }

            ans = min(ans, n - t);
        }

        return ans;
    }
    vector<int> output = {
        3,
        2,
        1
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "aabcaba",
        "dabdcbdcdcd",
        "aaabaaa"
    };
    vector<int> input2 = {
        0,
        2,
        2
    };
};