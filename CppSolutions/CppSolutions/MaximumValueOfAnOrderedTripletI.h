#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i

class MaximumValueOfAnOrderedTripletI {
public:
    // 0 ms, faster than 100% : 21.49 MB, less than 99.4%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    ans = max(ans, 1LL * (nums[i] - nums[j]) * nums[k]);
                }
            }
        }

        return ans;
    }
    vector<int> output = {
        77,
        133,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 12, 6, 1, 2, 7 },
        { 1, 10, 3, 4, 19 },
        { 1, 2, 3 }
    };
};