#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-of-interesting-subarrays

class CountOfInterestingSubarrays {
public:
    // 50 ms, faster than 72.77% : 122.66 MB, less than 67.54%
    int solution(vector<int> nums, int modulo, int k)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        long long ans = 0;
        int prefix = 0;
        m[0] = 1;
        for (int i = 0; i < n; i++) {
            prefix += nums[i] % modulo == k;
            ans += m[(prefix - k + modulo) % modulo];
            m[prefix % modulo]++;
        }
        return ans;
    }
    vector<int> output = {
        3,
        2
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 3, 2, 4 },
        { 3, 1, 9, 6 }
    };
    vector<int> input2 = {
        2,
        3
    };
    vector<int> input3 = {
        1,
        0
    };
};