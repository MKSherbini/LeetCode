#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

class MinimumCostToHireKWorkers {
public:
    // 15 ms, faster than 99.44% : 24.56 MB, less than 91.32%
    double solution(vector<int> quality, vector<int> wage, int k)
    {
        int n = size(quality);
        vector<pair<double, int>> v(n);
        for (size_t i = 0; i < n; i++) {
            v[i] = { 1.0 * wage[i] / quality[i], quality[i] };
        }
        sort(begin(v), end(v));

        priority_queue<int> pq;
        int qualities = 0;
        double ans = 1e9;
        for (size_t i = 0; i < n; i++) {
            pq.push(v[i].second);
            qualities += v[i].second;

            if (size(pq) > k) {
                qualities -= pq.top();
                pq.pop();
            }

            if (size(pq) == k) {
                ans = min(ans, qualities * v[i].first);
            }
        }

        return ans;
    }
    vector<double> output = {
        105.00000,
        30.66667
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 10, 20, 5 },
        { 3, 1, 10, 10, 1 }
    };
    vector<vector<int>> input2 = {
        { 70, 50, 30 },
        { 4, 8, 2, 2, 7 }
    };
    vector<int> input3 = {
        2,
        3
    };
};