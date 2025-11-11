#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/ones-and-zeroes

class OnesAndZeroes {
public:
    // 255 ms, faster than 13.97% : 107.07 MB, less than 13.19%
    int solution(vector<string> strs, int m, int n)
    {
        vector mem(strs.size(), vector(m + 1, vector(n + 1, -1)));
        function<int(int, int, int)> f = [&](int i, int z, int o) -> int {
            if (i == strs.size()) {
                return 0;
            }

            if (mem[i][z][o] != -1) {
                return mem[i][z][o];
            }

            int ret = f(i + 1, z, o);
            int tz = z, to = o;
            for (size_t j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0') {
                    tz--;
                } else {
                    to--;
                }
            }

            if (tz >= 0 && to >= 0) {
                ret = max(ret, 1 + f(i + 1, tz, to));
            }

            return mem[i][z][o] = ret;
        };

        return f(0, m, n);
    }
    vector<int> output = {
        4,
        2
    };
    static constexpr int const& inputs = 3;
    vector<vector<string>> input1 = {
        { "10", "0001", "111001", "1", "0" },
        { "10", "0", "1" }
    };
    vector<int> input2 = {
        5,
        1
    };
    vector<int> input3 = {
        3,
        1
    };
};