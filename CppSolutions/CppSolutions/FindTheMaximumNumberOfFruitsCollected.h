#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected

class FindTheMaximumNumberOfFruitsCollected {
public:
    // 10 ms, faster than 90% : 157.15 MB, less than 52.6%
    int solution(vector<vector<int>> fruits)
    {
        int n = size(fruits);

        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            ans += fruits[i][i];
        }

        function<bool(int, int)> valid = [&](int x, int n) -> bool {
            return x >= 0 && x < n;
        };

        vector<vector<int>> mem(n, vector<int>(n, -1));
        function<int(int, int)> f = [&](int i, int j) -> int {
            if (i <= j)
                return 0;

            if (i == n - 1 && j == n - 1)
                return 0;

            if (!valid(i, n) || !valid(j, n))
                return 0;

            if (mem[i][j] != -1)
                return mem[i][j];

            int ret = f(i, j + 1);
            ret = max(ret, f(i + 1, j + 1));
            ret = max(ret, f(i - 1, j + 1));
            Printer::print(i, j, ret);

            return mem[i][j] = ret + fruits[i][j];
        };

        ans += f(n - 1, 0);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i + 1; j < n; j++) {
                swap(fruits[i][j], fruits[j][i]);
            }
        }
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j <= i; j++) {
                mem[i][j] = -1;
            }
        }
        ans += f(n - 1, 0);

        return ans;
    }
    vector<int> output = {
        100,
        4
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2, 3, 4 }, { 5, 6, 8, 7 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } },
        { { 1, 1 }, { 1, 1 } }
    };
};