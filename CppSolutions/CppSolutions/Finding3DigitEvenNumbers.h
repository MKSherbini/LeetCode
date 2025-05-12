#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/finding-3-digit-even-numbers

class Finding3DigitEvenNumbers {
public:
    // 0 ms, faster than 100% : 12.28 MB, less than 99.4%
    vector<int> solution(vector<int> digits)
    {
        vector<int> f(10);
        for (auto d : digits)
            f[d]++;

        vector<int> ans;
        for (size_t i = 1; i < 10; i++) {
            if (!f[i])
                continue;
            f[i]--;
            for (size_t j = 0; j < 10; j++) {
                if (!f[j]) {
                    continue;
                }
                f[j]--;
                for (size_t k = 0; k < 10; k += 2) {
                    if (!f[k]) {
                        continue;
                    }
                    ans.push_back(i * 100 + j * 10 + k);
                }
                f[j]++;
            }
            f[i]++;
        }
        return ans;
    }
    vector<vector<int>> output = {
        { 102, 120, 130, 132, 210, 230, 302, 310, 312, 320 },
        { 222, 228, 282, 288, 822, 828, 882 },
        {}
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 1, 3, 0 },
        { 2, 2, 8, 8, 2 },
        { 3, 7, 5 }
    };
};