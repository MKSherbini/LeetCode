#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/partition-array-according-to-given-pivot

class PartitionArrayAccordingToGivenPivot {
public:
    // 7 ms, faster than 59.31% : 133.28 MB, less than 67.53%
    vector<int> solution(vector<int> nums, int pivot)
    {
        int n = nums.size();
        vector<int> ans;
        int eq = 0;
        for (size_t i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans.push_back(nums[i]);
            } else if (nums[i] == pivot) {
                eq++;
            }
        }
        for (size_t i = 0; i < eq; i++) {
			ans.push_back(pivot);
		}
        for (size_t i = 0; i < n; i++) {
			if (nums[i] > pivot) {
				ans.push_back(nums[i]);
			}
		}

        return ans;
    }
    vector<vector<int>> output = {
        { 9, 5, 3, 10, 10, 12, 14 },
        { -3, 2, 4, 3 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 9, 12, 5, 10, 14, 3, 10 },
        { -3, 4, 3, 2 }
    };
    vector<int> input2 = {
        10,
        2
    };
};