#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended

class MaximumNumberOfEventsThatCanBeAttended {
public:
    // 45 ms, faster than 97.29% : 74.82 MB, less than 85.96%
    int solution(vector<vector<int>> events)
    {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<>> pq;
        int ans = 0;
        int n = events.size();
        int d = 0;
        int i = 0;
        while (i < n || !pq.empty()) {
            while (i < n && events[i][0] <= d) {
                pq.push(events[i][1]);
                i++;
            }
            while (!pq.empty() && pq.top() < d) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans++;
                pq.pop();
            }
            d++;
        }
        return ans;
    }
    vector<int> output = {
        3,
        4,
        4,
        5,
        5
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2 }, { 2, 3 }, { 3, 4 } },
        { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 2 } },
        { { 1, 4 }, { 4, 4 }, { 2, 2 }, { 3, 4 }, { 1, 1 } },
        { { 1, 2 }, { 1, 2 }, { 3, 3 }, { 1, 5 }, { 1, 5 } },
        { { 1, 5 }, { 1, 5 }, { 1, 5 }, { 2, 3 }, { 2, 3 } }
    };
};