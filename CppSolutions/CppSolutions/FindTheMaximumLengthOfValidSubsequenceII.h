#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii

class FindTheMaximumLengthOfValidSubsequenceII {
public:
    // 94 ms, faster than 90.56% : 130.78 MB, less than 30.09%
    int solution(vector<int> nums, int k)
    {
        int n = nums.size();
        vector mem(k, vector<int>(k, 0));
        int ans = 0;
        for (auto num : nums) {
            num %= k;
            for (size_t i = 0; i < k; i++) {
                mem[num][i] = mem[i][num] + 1;
                ans = max(ans, mem[num][i]);
            }
        }

        return ans;
    }
    vector<int> output = {
        5,
        4
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 4, 5 },
        { 1, 4, 2, 3, 1, 4 }
    };
    vector<int> input2 = {
        2,
        3
    };
};