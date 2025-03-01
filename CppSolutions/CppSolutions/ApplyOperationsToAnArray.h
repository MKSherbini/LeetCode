#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/apply-operations-to-an-array

class ApplyOperationsToAnArray {
public:
    // 0 ms, faster than 100% : 13.16 MB, less than 62.05%
    vector<int> solution(vector<int> nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[j], nums[i]);
                j++;
            }
        }

        return nums;
    }
    vector<vector<int>> output = {
        { 1, 4, 2, 0, 0, 0 },
        { 1, 0 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 2, 1, 1, 0 },
        { 0, 1 }
    };
};