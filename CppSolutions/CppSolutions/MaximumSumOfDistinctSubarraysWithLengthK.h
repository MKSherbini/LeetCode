#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k

class MaximumSumOfDistinctSubarraysWithLengthK {
public:
    // 91 ms, faster than 93.63% : 98.22 MB, less than 49.04%
    int solution(vector<int> nums, int k)
    {
        int n = size(nums);

        long long ans = 0;
        unordered_map<int, int> m;
        long long c = 0, sum = 0;
        for (size_t i = 0; i < n; i++) {
            sum += nums[i];
            if (m[nums[i]]++ == 0)
                c++;

            if (i >= k) {
                sum -= nums[i - k], m[nums[i - k]]--;
                if (m[nums[i - k]] == 0)
                    c--;
            }

            if (c == k)
                ans = max(ans, sum);

            Printer::print(i, sum, c);
            Printer::print(m);
        }

        return ans;
    }
    vector<int> output = {
        15,
        0
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 5, 4, 2, 9, 9, 9 },
        { 4, 4, 4 }
    };
    vector<int> input2 = {
        3,
        3
    };
};