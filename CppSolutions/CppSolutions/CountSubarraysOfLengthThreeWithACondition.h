#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition

class CountSubarraysOfLengthThreeWithACondition {
public:
    // 0 ms, faster than 100% : 48.26 MB, less than 95.92%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
    vector<int> output = {
        1,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 1, 4, 1 },
        { 1, 1, 1 }
    };
};