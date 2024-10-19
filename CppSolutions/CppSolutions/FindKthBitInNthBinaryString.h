#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/

class FindKthBitInNthBinaryString {
public:
    // 0 ms, faster than 100% : 7.36 MB, less than 87.54%
    char solution(int n, int k)
    {
        vector<int> levels(n);
        levels[0] = 1;
        for (size_t i = 1; i < size(levels); i++) {
            levels[i] = levels[i - 1] * 2 + 1;
        }

        function<bool(int, int)> f = [&](int i, int k) -> bool {
            if (i == 0)
                return 0;

            int md = levels[i] / 2;
            if (k == md)
                return 1;

            if (k > md)
                return !f(i - 1, levels[i] - k - 1);

            return f(i - 1, k);
        };

        return '0' + f(n - 1, k - 1);
    }
    vector<char> output = {
        '0',
        '1'
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        3,
        4
    };
    vector<int> input2 = {
        1,
        11
    };
};