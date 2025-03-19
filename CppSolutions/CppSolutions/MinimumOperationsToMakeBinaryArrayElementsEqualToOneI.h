#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i

class MinimumOperationsToMakeBinaryArrayElementsEqualToOneI {
public:
    // 3 ms, faster than 89.05% : 139.94 MB, less than 74.5%
    int solution(vector<int> nums)
    {
        int k = 3;
        int n = nums.size();
        int ans = 0, flips = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] + flips) % 2 == 0) {
                if (i + k > n) return -1;
                flips++;
                ans++;
                nums[i] = -1;
            }

            if (i + 1 >= k && nums[i + 1 - k] == -1) {
                flips--;
            }
            Printer::print(flips, ans);
        }

        return ans;
    }
    vector<int> output = {
        3,
        -1
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 0, 1, 1, 1, 0, 0 },
        { 0, 1, 1, 1 }
    };
};