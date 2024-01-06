#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/4sum/

class Sum4
{
public:
	// 82 ms, faster than 39.04% : 13.4 MB, less than 97.02%
	vector<vector<int>> solution(vector<int> nums, int target) {
		sort(begin(nums), end(nums));
		vector<vector<int>> ans;
		for (int l = 0; l < (int)size(nums) - 3; l++) {
			if (l > 0 && nums[l] == nums[l - 1]) continue;
			for (int k = l + 1; k < (int)size(nums) - 2; k++) {
				if (k > l + 1 && nums[k] == nums[k - 1]) continue;
				int i = k + 1, j = size(nums) - 1;

				while (i < j) {
					if (0ll + nums[i] + nums[j] + nums[k] + nums[l] < target) {
						i++;
					}
					else if (0ll + nums[i] + nums[j] + nums[k] + nums[l] > target) {
						j--;
					}
					else {
						ans.push_back({ nums[i], nums[j], nums[k], nums[l] });
						do {
							i++;
						} while (i < j && nums[i] == nums[i - 1]);
						do {
							j--;
						} while (i < j && nums[j] == nums[j + 1]);
					}
				}
			}
		}
		return ans;
	}

	// 84 ms, faster than 38.58% : 13.4 MB, less than 97.02%
	vector<vector<int>> solution2(vector<int> nums, int target) {
		sort(begin(nums), end(nums));
		vector<vector<int>> ans;
		for (int l = 0; l < (int)size(nums) - 3; l++) {
			if (l > 0 && nums[l] == nums[l - 1]) continue;
			for (int k = l + 1; k < (int)size(nums) - 2; k++) {
				if (k > l + 1 && nums[k] == nums[k - 1]) continue;
				int i = k + 1, j = size(nums) - 1;

				while (i < j) {
					if (0ll + nums[i] + nums[j] + nums[k] + nums[l] < target) {
						i++;
					}
					else if (0ll + nums[i] + nums[j] + nums[k] + nums[l] > target) {
						j--;
					}
					else {
						ans.push_back({ nums[i], nums[j], nums[k], nums[l] });
						do {
							i++, j--;
						} while (i < j && nums[i] == nums[i - 1] && nums[j] == nums[j + 1]);
					}
				}
			}
		}
		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{-2,-1,1,2},{-2,0,0,2},{-1,0,0,1}},
		{{2,2,2,2}}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,0,-1,0,-2,2},
		{2,2,2,2,2}
	};
	vector<int> input2 = {
		0,
		8
	};
};