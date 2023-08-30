#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-replacements-to-sort-the-array/

class MinimumReplacementsToSortTheArray
{
public:
	// 80 ms, faster than 95.8% : 54.6 MB, less than 87.69%
	long long solution(vector<int> nums) {
		int n = size(nums);
		long long ans = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (nums[i] <= nums[i + 1]) continue;
			int k = ceil(1.0 * nums[i] / nums[i + 1]);
			ans += k - 1;
			nums[i] /= k;
		}

		return ans;
	}
	vector<int> output = {
		2,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,9,3},
		{1,2,3,4,5}
	};
};