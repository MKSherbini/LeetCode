#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/ipo/description/

class Ipo {
public:
    // 119 ms, faster than 95.8% : 81.46 MB, less than 90.92%
    int solution(int k, int w, vector<int> profits, vector<int> capital)
    {
        int n = size(profits);
        vector<pair<int, int>> v(n);
        for (size_t i = 0; i < n; i++) {
            v[i] = { capital[i], profits[i] };
        }
        sort(begin(v), end(v));

        priority_queue<int> pq;
        int i = 0;
        while (k--) {
            while (i < n && v[i].first <= w) {
                pq.push(v[i++].second);
            }

            if (pq.empty())
                break;
            else
                w += pq.top(), pq.pop();
        }

        return w;
    }
    vector<int> output = {
        4,
        6
    };
    static constexpr int const& inputs = 4;
    vector<int> input1 = {
        2,
        3
    };
    vector<int> input2 = {
        0,
        0
    };
    vector<vector<int>> input3 = {
        { 1, 2, 3 },
        { 1, 2, 3 }
    };
    vector<vector<int>> input4 = {
        { 0, 1, 1 },
        { 0, 1, 2 }
    };
};