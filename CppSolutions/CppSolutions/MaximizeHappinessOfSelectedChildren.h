#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximize-happiness-of-selected-children/description/

class MaximizeHappinessOfSelectedChildren {
public:
    // 138 ms, faster than 98.02% : 107 MB, less than 98.04%
    int solution(vector<int> happiness, int k)
    {
        int n = size(happiness);
        sort(begin(happiness), end(happiness), greater());

        long long ans = 0, penalty = 0;
        for (size_t i = 0; i < k; i++) {
            ans += max(0LL, happiness[i] - penalty);
            penalty++;
        }

        return ans;
    }
    vector<int> output = {
        4,
        1,
        5
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2, 3 },
        { 1, 1, 1, 1 },
        { 2, 3, 4, 5 }
    };
    vector<int> input2 = {
        2,
        2,
        1
    };
};