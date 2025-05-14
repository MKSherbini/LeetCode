#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/total-characters-in-string-after-transformations-i

class TotalCharactersInStringAfterTransformationsI {
public:
    // 728 ms, faster than 47.81% : 466.77 MB, less than 47.32%
    int solution(string s, int t)
    {
        long long ans = 0;
        int n = s.size();
        const long long MOD = 1e9 + 7;
        vector<long long> f(26);
        for (int i = 0; i < n; i++) {
            f[s[i] - 'a']++;
        }
        Printer::print(f);

        for (int i = 0; i < t; i++) {
            auto f2 = f;
            for (int i = 25 - 1; i >= 0; i--) {
                f[i + 1] = f[i];
            }
            f[0] = 0;
            f[0] += f2[25];
            f[0] %= MOD;
            f[1] += f2[25];
            f[1] %= MOD;

            Printer::print(f);
        }

        for (int i = 0; i < 26; i++) {
            ans += f[i];
            ans %= MOD;
        }

        return ans;
    }
    vector<int> output = {
        7,
        5
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "abcyy",
        "azbk"
    };
    vector<int> input2 = {
        2,
        1
    };
};