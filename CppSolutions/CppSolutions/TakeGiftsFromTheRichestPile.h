#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/take-gifts-from-the-richest-pile

class TakeGiftsFromTheRichestPile {
public:
    // 0 ms, faster than 100% : 12.91 MB, less than 89.48%
    int solution(vector<int> gifts, int k)
    {
        priority_queue<int> pq;
        long long sum = 0;
        for (auto g : gifts)
            pq.push(g), sum += g;

        while (k--) {
            int r = sqrt(pq.top());
            sum -= pq.top() - r;
            pq.push(r);
            pq.pop();
        }

        return sum;
    }
    vector<int> output = {
        29,
        4
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 25, 64, 9, 4, 100 },
        { 1, 1, 1, 1 }
    };
    vector<int> input2 = {
        4,
        4
    };
};