#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three

class FindMinimumOperationsToMakeAllElementsDivisibleByThree {
public:
    // 0 ms, faster than 100% : 23.05 MB, less than 97.64%
    int solution(vector<int> nums)
    {
        int ans = 0;
        for (auto x : nums) {
            ans += min(3 - x % 3, x % 3);
        }

        return ans;
    }
    vector<int> output = {
        3,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 4 },
        { 3, 6, 9 }
    };
};