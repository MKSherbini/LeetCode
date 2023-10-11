#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

class MinimumNumberOfOperationsToMakeArrayContinuous
{
public:
	// 184 ms, faster than 63.33% : 64.4 MB, less than 81.24%
	int solution(vector<int> nums) {
		sort(begin(nums), end(nums));
		int n = size(nums);
		int m = unique(begin(nums), end(nums)) - begin(nums);
		Printer::print(m);
		Printer::print(nums);

		int ans = n;
		for (size_t i = 0; i < m; i++) {
			int l = nums[i], r = l + n - 1;
			int j = upper_bound(begin(nums), begin(nums) + m, r) - begin(nums);
			int len = j - i;
			Printer::print(l, r, j, len);
			ans = min(ans, n - len);
		}

		return ans;
	}
	vector<int> output = {
		6,
		2,
		0,
		1,
		3
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{8,10,16,18,10,10,16,13,13,16},
		{8,5,9,9,8,4},
		{4,2,5,3},
		{1,2,3,5,6},
		{1,10,100,1000}
	};
};