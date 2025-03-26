#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid

class MinimumOperationsToMakeAUniValueGrid {
public:
    // 81 ms, faster than 5.47% : 107.88 MB, less than 6.38%
    int solution(vector<vector<int>> grid, int x)
    {
        int n = grid.size(), m = grid[0].size();

        vector<int> nums;
        for (auto v : grid) {
            for (auto y : v) {
                nums.push_back(y);
            }
        }

        sort(nums.begin(), nums.end());
        int goal = nums[nums.size() / 2];

        int ans = 0;
        for (auto v : grid) {
            for (auto y : v) {
                if (abs(y - goal) % x != 0) {
					return -1;
				}
                ans += abs(y - goal) / x;
            }
        }

        return ans;
    }
    vector<int> output = {
        4,
        5,
        -1
    };
    static constexpr int const& inputs = 2;
    vector<vector<vector<int>>> input1 = {
        { { 2, 4 }, { 6, 8 } },
        { { 1, 5 }, { 2, 3 } },
        { { 1, 2 }, { 3, 4 } }
    };
    vector<int> input2 = {
        2,
        1,
        2
    };
};