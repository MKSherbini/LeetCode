#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array

class CountEqualAndDivisiblePairsInAnArray {
public:
    // 0 ms, faster than 100% : 15.38 MB, less than 91.08%
    int solution(vector<int> nums, int k)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
    vector<int> output = {
        4,
        0
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 3, 1, 2, 2, 2, 1, 3 },
        { 1, 2, 3, 4 }
    };
    vector<int> input2 = {
        2,
        1
    };
};