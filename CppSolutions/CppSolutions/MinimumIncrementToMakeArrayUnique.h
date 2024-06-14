#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/

class MinimumIncrementToMakeArrayUnique {
public:
    // 101 ms, faster than 90.35% : 68.97 MB, less than 93.9%
    int solution(vector<int> nums)
    {
        sort(begin(nums), end(nums));
        int last = -1;
        int ans = 0;
        for (auto x : nums) {
            if (last >= x) {
                last++;
                ans += last - x;
            } else {
                last = x;
            }
        }

        return ans;
    }
    vector<int> output = {
        1,
        6
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 2, 2 },
        { 3, 2, 1, 2, 1, 7 }
    };
};