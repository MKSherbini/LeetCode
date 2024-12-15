#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-average-pass-ratio

class MaximumAveragePassRatio {
public:
    // 415 ms, faster than 41.03% : 92.12 MB, less than 96.24%
    double solution(vector<vector<int>> classes, int extraStudents)
    {
        auto cmp = [&](const auto& a, const auto& b) {
            auto d1 = 1. * (a.first + 1) / (a.second + 1) - 1. * a.first / a.second;
            auto d2 = 1. * (b.first + 1) / (b.second + 1) - 1. * b.first / b.second;
            return d1 < d2;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (auto& c : classes)
            pq.push({ c[0], c[1] });

        while (extraStudents--) {
            Printer::print(pq.top());
            pq.push({ pq.top().first + 1, pq.top().second + 1 });
            pq.pop();
        }

        double ans = 0;
        while (!empty(pq)) {
            ans += 1. * pq.top().first / pq.top().second;
            pq.pop();
        }

        return ans / size(classes);
    }
    vector<double> output = {
        0.78333,
        0.53485
    };
    static constexpr int const& inputs = 2;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2 }, { 3, 5 }, { 2, 2 } },
        { { 2, 4 }, { 3, 9 }, { 4, 5 }, { 2, 10 } }
    };
    vector<int> input2 = {
        2,
        4
    };
};