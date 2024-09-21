#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/lexicographical-numbers/description/

class LexicographicalNumbers {
public:
    // 6 ms, faster than 78.34% : 13.65 MB, less than 76.44%
    vector<int> solution(int n)
    {
        auto calcLen = [](int x) {
            int c = 0;
            while (x) {
                x /= 10;
                c++;
            }

            return c;
        };

        int len = calcLen(n);
        vector<int> ans;
        function<void(int, int)> f = [&](int pos, int cur) -> void {
            if (cur <= n && cur != 0)
                ans.push_back(cur);

            if (pos == len) {
                return;
            }

            cur *= 10;
            if (cur != 0)
                f(pos + 1, cur);

            for (size_t i = 1; i <= 9; i++) {
                f(pos + 1, cur + i);
            }
        };
        f(0, 0);

        return ans;
    }
    vector<vector<int>> output = {
        { 1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9 },
        { 1, 2 }
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        13,
        2
    };
};