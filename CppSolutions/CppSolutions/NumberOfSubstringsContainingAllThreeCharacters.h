#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class NumberOfSubstringsContainingAllThreeCharacters {
public:
    // 3 ms, faster than 90.05% : 10.91 MB, less than 81.05%
    int solution(string s)
    {
        int n = size(s);
        vector<int> f(3);
        int i = 0;
        int ans = 0;
        for (size_t j = 0; j < n; j++) {
            f[s[j] - 'a']++;
            while (f[0] && f[1] && f[2]) {
                f[s[i++] - 'a']--;
                ans += n - j;
            }
        }

        return ans;
    }
    vector<int> output = {
        10,
        3,
        1
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "abcabc",
        "aaacb",
        "abc"
    };
};