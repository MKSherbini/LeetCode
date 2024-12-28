#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays

class MaximumSumOf3NonOverlappingSubarrays {
public:
    // 1004 ms, faster than 5.96% : 89.84 MB, less than 5.15%
    vector<int> solution(vector<int> nums, int k)
    {
        int n = size(nums);
        vector<int> pre(nums);
        for (size_t i = 1; i < n; i++) {
            pre[i] += pre[i - 1];
        }

        const long long OO = 1e15;
        vector mem(n, vector<pair<long long, vector<int>>>(3, { -1, {} }));
        function<pair<long long, vector<int>>(int, int)> f = [&](int i, int left) -> pair<long long, vector<int>> {
            if (i < 0 || !left)
                return { 0, {} };

            if (mem[i][left - 1].first != -1)
                return mem[i][left - 1];

            auto leave = f(i - 1, left);
            if (left && i - k + 1 >= 0) {
                auto pick = f(i - k, left - 1);
                pick.first += pre[i] - pre[i - k + 1] + nums[i - k + 1];
                if (pick.first > leave.first) {
                    pick.second.push_back(i - k + 1);
                    return mem[i][left - 1] = pick;
                }
            }

            return mem[i][left - 1] = leave;
        };

        return f(n - 1, 3).second;
    }
    vector<vector<int>> output = {
        { 0, 3, 5 },
        { 0, 2, 4 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2, 1, 2, 6, 7, 5, 1 },
        { 1, 2, 1, 2, 1, 2, 1, 2, 1 }
    };
    vector<int> input2 = {
        2,
        2
    };
};