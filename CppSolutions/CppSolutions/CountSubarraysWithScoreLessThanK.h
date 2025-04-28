#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-subarrays-with-score-less-than-k

class CountSubarraysWithScoreLessThanK {
public:
    // 0 ms, faster than 100% : 98.86 MB, less than 97.61%
    long long solution(vector<int> nums, int k)
    {
        int n = nums.size();

        long long ans = 0;
        long long sum = 0;
        int i = 0;
        for (int j = 0; j < n; ++j) {
            sum += nums[j];
            while (sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            ans += j - i + 1;
        }

        return ans;
    }
    vector<int> output = {
        6,
        5
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 2, 1, 4, 3, 5 },
        { 1, 1, 1 }
    };
    vector<int> input2 = {
        10,
        5
    };
};