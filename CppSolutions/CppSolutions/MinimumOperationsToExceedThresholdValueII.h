#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii

class MinimumOperationsToExceedThresholdValueII {
public:
    // 85 ms, faster than 92.04% : 98.94 MB, less than 61.54%
    int solution(vector<int> nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto x : nums)
            pq.push(x);

        int ans = 0;
        Printer::print(pq);
        while (size(pq) >= 2 && pq.top() < k) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();

            pq.push(2 * x + y);
            ans++;
        }

        return ans;
    }
    vector<int> output = {
        2,
        4,
        3
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 2, 11, 10, 1, 3 },
        { 1, 1, 2, 4, 9 },
        { 97, 73, 5, 78 }
    };
    vector<int> input2 = {
        10,
        20,
        98
    };
};