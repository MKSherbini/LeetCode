#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/set-mismatch/

class SetMismatch
{
public:
	// 21 ms, faster than 99.57% : 21.2 MB, less than 99.95%
	vector<int> solution(vector<int> nums) {
		vector<int> ans(2);

		for (auto x : nums) {
			if (nums[abs(x) - 1] < 0)
				ans[0] = abs(x);
			else
				nums[abs(x) - 1] = -nums[abs(x) - 1];
		}

		for (size_t i = 0; i < size(nums); i++)
			if (nums[i] > 0) {
				ans[1] = i + 1;
				break;
			}

		return ans;
	}
	vector<vector<int>> output = {
		{2,3},
		{1,2}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,2,4},
		{1,1}
	};
};