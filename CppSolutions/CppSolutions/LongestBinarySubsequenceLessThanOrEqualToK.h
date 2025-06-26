#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k

class LongestBinarySubsequenceLessThanOrEqualToK {
public:
    // 0 ms, faster than 100% : 9.27 MB, less than 100%
    int solution(string s, int k)
    {
        int n = s.size();
        int ans = 0, acc = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                ans++;
            } else {
                if (ans < 31 && acc + (1 << ans) <= k) {
                    acc += (1 << ans);
                    ans++;
                }
            }
        }

        return ans;
    }
    vector<int> output = {
        5,
        6,
        31
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "1001010",
        "00101001",
        "001010101011010100010101101010010"
    };
    vector<int> input2 = {
        5,
        1,
        93951055
    };
};