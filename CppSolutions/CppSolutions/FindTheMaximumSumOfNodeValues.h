#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/

class FindTheMaximumSumOfNodeValues {
public:
    // 158 ms, faster than 95.56% : 125.61 MB, less than 67.56%
    long long solution(vector<int> nums, int k, vector<vector<int>> edges)
    {
        int n = size(nums);
        long long sum = 0;
        int flips = 0;
        for (size_t i = 0; i < n; i++) {
            if ((nums[i] ^ k) > nums[i])
                flips++;
            sum += max(nums[i], nums[i] ^ k);
        }

        long long ans = 0;
        if (flips & 1) {
            for (size_t i = 0; i < n; i++) {
                if ((nums[i] ^ k) > nums[i])
                    ans = max(ans, sum - (nums[i] ^ k) + nums[i]);
                else
                    ans = max(ans, sum + (nums[i] ^ k) - nums[i]);
            }
        } else
            ans = sum;

        return ans;
    }
    vector<int> output = {
        260,
        6,
        5,
        9,
        42
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 24, 78, 1, 97, 44 },
        { 1, 2, 1 },
        { 1, 1, 1 },
        { 2, 3 },
        { 7, 7, 7, 7, 7, 7 }
    };
    vector<int> input2 = {
        6,
        3,
        3,
        7,
        3
    };
    vector<vector<vector<int>>> input3 = {
        { { 0, 2 }, { 1, 2 }, { 4, 2 }, { 3, 4 } },
        { { 0, 1 }, { 0, 2 } },
        { { 0, 1 }, { 0, 2 } },
        { { 0, 1 } },
        { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 0, 5 } }
    };
};