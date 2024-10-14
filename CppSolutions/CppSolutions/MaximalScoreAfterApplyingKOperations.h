#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/

class MaximalScoreAfterApplyingKOperations {
public:
    // 191 ms, faster than 68.33% : 79.46 MB, less than 73.32%
    long long solution(vector<int> nums, int k)
    {
        priority_queue<int> pq;
        for (auto a : nums)
            pq.push(a);

        long long ans = 0;
        while (k--) {
            int x = pq.top();
            pq.pop();
            ans += x;
            pq.push((x + 2) / 3);
        }

        return ans;
    }
    vector<int> output = {
        50,
        17
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 10, 10, 10, 10, 10 },
        { 1, 10, 3, 3, 3 }
    };
    vector<int> input2 = {
        5,
        3
    };
};