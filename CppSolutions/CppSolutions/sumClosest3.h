#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/3sum-closest/

class SumClosest3
{
public:
	// 374 ms, faster than 70.04% : 16.2 MB, less than 98.3%
	int solution(vector<int> nums, int target) {
		int n = size(nums);
		sort(begin(nums), end(nums));

		int ans = 1e5;
		for (size_t i = 0; i < n; i++)
		{
			int j = i + 1, k = n - 1;

			while (j < k)
			{
				int selected = nums[j] + nums[i] + nums[k];
				if (abs(ans - target) > abs(selected - target))
					ans = selected;

				if (selected > target)
					k--;
				else
					j++;
			}

		}

		return ans;
	}
	vector<int> output = {
		2,
		0
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{-1,2,1,-4},
		{0,0,0}
	};
	vector<int> input2 = {
		1,
		1
	};
};