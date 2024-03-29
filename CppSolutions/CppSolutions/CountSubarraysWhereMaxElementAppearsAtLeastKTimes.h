#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

class CountSubarraysWhereMaxElementAppearsAtLeastKTimes
{
public:
	// 122 ms, faster than 82.95% : 119.9 MB, less than 84.3%
	long long solution(vector<int> nums, int k) {
		int n = size(nums);
		long long ans = 0;
		int mx = *max_element(begin(nums), end(nums));
		for (int i = 0, st = 0; i < n; i++) {
			if (nums[i] == mx) k--;
			while (k == 0) {
				if (nums[st] == mx) k++;
				st++;
			}
			ans += st;
		}
		return ans;
	}
	vector<int> output = {
		6,
		0
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,3,2,3,3},
		{1,4,2,1}
	};
	vector<int> input2 = {
		2,
		3
	};
};