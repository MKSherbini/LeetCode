#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k

class PartitionArraySuchThatMaximumDifferenceIsK {
public:
    // 30 ms, faster than 84.68% : 86.85 MB, less than 70.53%
    int solution(vector<int> nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1, last = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] - last > k) {
                ans++;
                last = nums[i];
            }
        }

        return ans;
    }
    vector<int> output = {
        2,
        2,
        3
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 3, 6, 1, 2, 5 },
        { 1, 2, 3 },
        { 2, 2, 4, 5 }
    };
    vector<int> input2 = {
        2,
        1,
        0
    };
};