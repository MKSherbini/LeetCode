#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/most-beautiful-item-for-each-query

class MostBeautifulItemForEachQuery {
public:
    // 63 ms, faster than 45.9% : 97.04 MB, less than 42.91%
    vector<int> solution(vector<vector<int>> items, vector<int> queries)
    {
        sort(begin(items), end(items), [&](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        vector<int> mx(size(items));
        mx[0] = items[0][1];
        for (size_t i = 1; i < size(items); i++) {
            mx[i] = max(mx[i - 1], items[i][1]);
        }

        vector<int> ans(size(queries));
        for (size_t i = 0; i < size(queries); i++) {
            auto it = upper_bound(begin(items), end(items), vector { queries[i], INT_MAX }) - begin(items);
            ans[i] = it == 0 ? 0 : mx[it - 1];
        }

        return ans;
    }
    vector<vector<int>> output = {
        { 2, 4, 5, 5, 6, 6 },
        { 4 },
        { 0 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2 }, { 3, 2 }, { 2, 4 }, { 5, 6 }, { 3, 5 } },
        { { 1, 2 }, { 1, 2 }, { 1, 3 }, { 1, 4 } },
        { { 10, 1000 } }
    };
    vector<vector<int>> input2 = {
        { 1, 2, 3, 4, 5, 6 },
        { 1 },
        { 5 }
    };
};