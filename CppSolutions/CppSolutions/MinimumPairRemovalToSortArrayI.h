#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i

class MinimumPairRemovalToSortArrayI {
public:
    // 0 ms, faster than 100% : 26.44 MB, less than 81.64%
    int solution(vector<int> nums)
    {
        int ans = 0;
        while (nums.size() > 1) {
            int sorted = 1;
            int mnSum = INT_MAX;
            int mnI = -1;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    sorted = 0;
                }
               
                int sum = nums[i] + nums[i + 1];
                if (sum < mnSum) {
                    mnSum = sum;
                    mnI = i;
                }
            }
            if (sorted) {
                break;
            }
            ans++;
            nums[mnI] = mnSum;
            nums.erase(nums.begin() + mnI + 1);
        }

        return ans;
    }
    vector<int> output = {
        2,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 5, 2, 3, 1 },
        { 1, 2, 2 }
    };
};