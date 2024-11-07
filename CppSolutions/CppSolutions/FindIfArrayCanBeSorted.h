#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-if-array-can-be-sorted

class FindIfArrayCanBeSorted {
public:
    // 0 ms, faster than 100% : 31.15 MB, less than 86.38%
    uint8_t solution(vector<int> nums)
    {
        int n = size(nums);
        int mx = nums[0];
        int pmx = INT_MIN;
        int bits = __builtin_popcount(nums[0]);
        for (size_t i = 1; i < n; i++) {
            if (nums[i] < pmx)
                return 0;
            if (__builtin_popcount(nums[i]) != bits) {
                pmx = mx;
                bits = __builtin_popcount(nums[i]);
            }
            if (nums[i] < pmx)
                return 0;
            mx = max(mx, nums[i]);
            Printer::print(i, pmx, mx);
        }

        return 1;
    }

    // 0 ms, faster than 100% : 31.08 MB, less than 94.82%
    uint8_t solution2(vector<int> nums)
    {
        int n = size(nums);
        for (size_t i = 0; i < n - 1; i++) {
            for (size_t j = 0; j < n - i - 1; j++) {
                if (nums[j] <= nums[j + 1]) {
                    continue;
                }

                if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1])) {
                    swap(nums[j], nums[j + 1]);
                } else {
                    return 0;
                }
            }
        }

        return 1;
    }
    vector<uint8_t> output = {
        true,
        true,
        false,
        false
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 8, 4, 2, 30, 15 },
        { 1, 2, 3, 4, 5 },
        { 3, 16, 8, 4, 2 },
        { 20, 16 }
    };
};