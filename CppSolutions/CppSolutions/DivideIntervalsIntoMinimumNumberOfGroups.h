#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/

class DivideIntervalsIntoMinimumNumberOfGroups {
public:
    // Can also use line sweep
    // 397 ms, faster than 31.31% : 124.55 MB, less than 32.21%
    int solution(vector<vector<int>> intervals)
    {
        int n = size(intervals);
        sort(begin(intervals), end(intervals), [](const auto& a, const auto& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        });

        Printer::print(intervals);
        multiset<int> s;
        for (auto i : intervals) {

            auto it = s.upper_bound(-i[0]);
            if (it == end(s)) {
                s.insert(-i[1]);
            } else {
                s.erase(it);
                s.insert(-i[1]);
            }

            Printer::print(i, s);
        }

        return size(s);
    }
    vector<int> output = {
        3,
        1
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 5, 10 }, { 6, 8 }, { 1, 5 }, { 2, 3 }, { 1, 10 } },
        { { 1, 3 }, { 5, 6 }, { 8, 10 }, { 11, 13 } }
    };
};