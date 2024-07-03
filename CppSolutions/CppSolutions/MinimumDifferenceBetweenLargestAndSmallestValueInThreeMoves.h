#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

class MinimumDifferenceBetweenLargestAndSmallestValueInThreeMoves {
public:
    // 66 ms, faster than 72.7% : 38.65 MB, less than 80.72%
    int solution(vector<int> nums)
    {
        int n = size(nums);
        if (n <= 4)
            return 0;

        sort(begin(nums), end(nums));
        int ans = INT_MAX;
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                if (i + j > 3)
                    continue;
                //Printer::print(nums[i], nums[n - j - 1]);
                ans = min(ans, nums[n - j - 1] - nums[i]);
            }
        }

        return ans;
    }
    vector<int> output = {
        0,
        1,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 5, 3, 2, 4 },
        { 1, 5, 0, 10, 14 },
        { 3, 100, 20 }
    };
};