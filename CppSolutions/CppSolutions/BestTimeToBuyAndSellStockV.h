#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v

class BestTimeToBuyAndSellStockV {
public:
    // 1273 ms, faster than 8.64% : 345.22 MB, less than 20.26%
    int solution(vector<int> prices, int k)
    {
        int n = prices.size();
        const long long OO = 1e9;
        vector mem(n, vector(k + 1, vector(3, -1ll)));
        function<long long(int, int, int)> f = [&](int i, int k, int transaction) -> long long {
            if (i >= n || k == 0)
                return transaction == 0 ? 0 : -OO;

            if (mem[i][k][transaction] != -1) {
                return mem[i][k][transaction];
            }
            long long ret = f(i + 1, k, transaction);
            if (transaction == 0) {
                ret = max(ret, prices[i] + f(i + 1, k, 1));
                ret = max(ret, -prices[i] + f(i + 1, k, 2));
            } else if (transaction == 1) {
                ret = max(ret, -prices[i] + f(i + 1, k - 1, 0));
            } else {
                ret = max(ret, prices[i] + f(i + 1, k - 1, 0));
            }

            return mem[i][k][transaction] = ret;
        };

        return f(0, k, 0);
    }
    vector<int> output = {
        14,
        36
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 7, 9, 8, 2 },
        { 12, 16, 19, 19, 8, 1, 19, 13, 9 }
    };
    vector<int> input2 = {
        2,
        3
    };
};