#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

class MinimumOperationsToReduceXToZero
{
public:
	// 331 ms, faster than 48.83% : 102.9 MB, less than 51.05%
	int solution(vector<int> nums, int x) {
		auto prefix = nums;
		for (size_t i = 1; i < prefix.size(); i++)
			prefix[i] += prefix[i - 1];


		int sum = 0;
		int ans = nums.size() + 1;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			sum += nums[i];
			int idx = lower_bound(begin(prefix), end(prefix), x - sum) - begin(prefix);
			Printer::print(idx, i, prefix[idx], sum);
			if (idx < i && prefix[idx] == x - sum)
				ans = min(ans, (int)nums.size() - i + idx + 1);
			if (prefix[i] == x)
				ans = min(ans, i + 1);
			if (sum == x)
				ans = min(ans, (int)nums.size() - i);
		}
		return ans == nums.size() + 1 ? -1 : ans;
	}
	vector<int> output = {
		2,
		-1,
		5,
		1
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,1,4,2,3},
		{5,6,7,8,9},
		{3,2,20,1,1,3},
		{5,2,3,1,1}
	};
	vector<int> input2 = {
		5,
		4,
		10,
		5
	};
};