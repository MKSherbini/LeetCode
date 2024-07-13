#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/

class FinalPricesWithASpecialDiscountInAShop {
public:
    // 0 ms, faster than 100% : 12.43 MB, less than 38.88%
    vector<int> solution(vector<int> prices)
    {
        int n = size(prices);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!empty(st) && st.top() > prices[i]) {
                st.pop();
            }
            int deal = empty(st) ? 0 : st.top();
            st.push(prices[i]);
            prices[i] -= deal;
        }

        return prices;
    }
    vector<vector<int>> output = {
        { 4, 2, 4, 2, 3 },
        { 1, 2, 3, 4, 5 },
        { 9, 0, 1, 6 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 8, 4, 6, 2, 3 },
        { 1, 2, 3, 4, 5 },
        { 10, 1, 1, 6 }
    };
};