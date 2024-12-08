#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/two-best-non-overlapping-events

class TwoBestNonOverlappingEvents {
public:
    // 114 ms, faster than 49.57% : 137.51 MB, less than 57.33%
    int solution(vector<vector<int>> events)
    {
        sort(begin(events), end(events));

        int n = size(events);
        vector<int> mx(n);
        mx.back() = events.back().back();
        for (int i = n - 2; i >= 0; i--) {
            mx[i] = max(mx[i + 1], events[i].back());
        }
        Printer::print(events, mx);

        int ans = mx[0];
        for (size_t i = 0; i < n; i++) {
            auto j = lower_bound(begin(events), end(events), vector { events[i][1] + 1 }) - begin(events);
            if (j == n)
                continue;
            Printer::print(i, j);
            ans = max(ans, events[i].back() + mx[j]);
        }

        return ans;
    }
    vector<int> output = {
        4,
        5,
        8,
        142
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 3, 2 }, { 4, 5, 2 }, { 2, 4, 3 } },
        { { 1, 3, 2 }, { 4, 5, 2 }, { 1, 5, 5 } },
        { { 1, 5, 3 }, { 1, 5, 1 }, { 6, 6, 5 } },
        { { 19, 36, 24 }, { 70, 90, 11 }, { 61, 78, 36 }, { 38, 38, 70 }, { 39, 83, 72 }, { 8, 46, 5 }, { 64, 69, 49 }, { 88, 89, 39 }, { 53, 77, 24 }, { 35, 76, 26 } }
    };
};