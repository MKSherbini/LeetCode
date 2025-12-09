#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-special-triplets

class CountSpecialTriplets {
public:
    // 832 ms, faster than 59.49% : 427.78 MB, less than 50%
    int solution(vector<int> nums)
    {
        int n = nums.size();
        unordered_map<int, int> seen;
        unordered_map<int, int> future;
        for (int num : nums) {
            future[num]++;
        }

        long long ans = 0;
        int mod = (int)1e9 + 7;
        for (size_t i = 0; i < n; i++) {
            future[nums[i]]--;
            ans += 1ll * seen[nums[i] * 2] * future[nums[i] * 2];
            ans %= mod;
            seen[nums[i]]++;
        }

        return ans;
    }
    vector<int> output = {
        1,
        1,
        2
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 6, 3, 6 },
        { 0, 1, 0, 0 },
        { 8, 4, 2, 8, 4 }
    };
};