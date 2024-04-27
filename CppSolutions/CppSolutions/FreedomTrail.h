#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/freedom-trail/

class FreedomTrail {
public:
    // 6 ms, faster than 91.51% : 15.1 MB, less than 54.25%
    int solution(string ring, string key)
    {
        int n = size(ring), m = size(key);

        vector chars(26, vector<int>());
        for (size_t i = 0; i < n; i++) {
            chars[ring[i] - 'a'].push_back(i);
        }

        vector mem(n, vector(m, -1));
        function<int(int, int)> f = [&](int i, int j) -> int {
            if (j == m)
                return 0;

            int& ret = mem[i][j];
            if (ret != -1)
                return ret;

            ret = 1e7;
            for (auto c : chars[key[j] - 'a']) {
                ret = min(ret, 1 + min((n - max(c, i)) + min(c, i), abs(c - i)) + f(c, j + 1));
            }

            return ret;
        };

        return f(0, 0);
    }
    vector<int> output = {
        4,
        13
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "godding",
        "godding"
    };
    vector<string> input2 = {
        "gd",
        "godding"
    };
};