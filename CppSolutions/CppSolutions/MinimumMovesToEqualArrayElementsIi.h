#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class MinimumMovesToEqualArrayElementsIi
{
public:
	// 10 ms, faster than 90.92% : 10.8 MB, less than 59.74%
	int solution(vector<int> nums) {
		sort(begin(nums), end(nums));
		int sz = size(nums);

		for (size_t i = 1; i < size(nums); i++)
			nums[i] += nums[i - 1];

		long long mn = INT32_MAX;
		for (size_t i = 0; i < size(nums); i++) {
			long long less = i == 0 ? 0 : (long long)i * (nums[i] - nums[i - 1]) - nums[i - 1];
			long long more = (long long)nums[sz - 1] - nums[i] - (sz - i - 1) * (i == 0 ? nums[i] : (nums[i] - nums[i - 1]));
			mn = min(mn, less + more);
			Printer::print(nums[i], less, more);
		}

		return mn;
	}

	// 7 ms, faster than 97.98% : 10.9 MB, less than 15.75%
	int solution2(vector<int> nums) {
		sort(begin(nums), end(nums));
		int sz = size(nums);
		vector<int> pre(nums);

		for (size_t i = 1; i < size(pre); i++)
			pre[i] += pre[i - 1];

		long long mn = INT32_MAX;
		for (size_t i = 0; i < size(nums); i++) {
			long long less = i == 0 ? 0 : (long long)i * nums[i] - pre[i - 1];
			long long more = (long long)pre[sz - 1] - pre[i] - (sz - i - 1) * nums[i];
			mn = min(mn, less + more);
			Printer::print(nums[i], less, more);
		}

		return mn;
	}
	vector<int> output = {
		2,
		16
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3},
		{1,10,2,9}
	};
};