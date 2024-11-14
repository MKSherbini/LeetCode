#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store

class MinimizedMaximumOfProductsDistributedToAnyStore {
public:
    // 1964 ms, faster than 5.24% : 106.46 MB, less than 14.75%
    int solution(int n, vector<int> quantities)
    {
        auto cmp = [&](const auto& a, const auto& b) {
            return 1. * a.first / a.second < 1. * b.first / b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (auto x : quantities)
            pq.push({ x, 1 });

        Printer::print(pq);
        int m = size(quantities);
        while (m < n) {
            auto &[v, c] = pq.top();
            pq.push({ v, c + 1 });
            pq.pop();

            m++;
            Printer::print(pq);
        }

        return (pq.top().first + pq.top().second - 1) / pq.top().second;
    }
    vector<int> output = {
        3,
        5,
        100000
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        6,
        7,
        1
    };
    vector<vector<int>> input2 = {
        { 11, 6 },
        { 15, 10, 10 },
        { 100000 }
    };
};