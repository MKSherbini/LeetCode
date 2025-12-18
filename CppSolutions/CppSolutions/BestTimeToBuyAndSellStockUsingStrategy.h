#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy

class BestTimeToBuyAndSellStockUsingStrategy {
public:
    // 0 ms, faster than 100% : 302.69 MB, less than 86.72%
    int solution(vector<int> prices, vector<int> strategy, int k)
    {
        int n = prices.size();
        long long cur = 0;
        for (size_t i = 0; i < n; i++) {
            cur += 1ll * strategy[i] * prices[i];
        }

        long long ans = cur;
        int h = k / 2;
        for (size_t i = 0; i < k; i++) {
            cur -= 1ll * strategy[i] * prices[i];
            if (i + h < k) {
                cur += prices[i + h];
            }
        }
        ans = max(ans, cur);

        for (size_t i = k; i < n; i++) {
            cur += 1ll * -strategy[i] * prices[i] + strategy[i - k] * prices[i - k];
            cur += 1ll * prices[i] - prices[i - h];
            ans = max(ans, cur);
        }

        return ans;
    }
    vector<int> output = {
        10,
        9,

    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 4, 2, 8 },
        { 5, 4, 3 },

    };
    vector<vector<int>> input2 = {
        { -1, 0, 1 },
        { 1, 1, 0 },

    };
    vector<int> input3 = {
        2,
        2,

    };
};