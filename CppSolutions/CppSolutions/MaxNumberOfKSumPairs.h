#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/max-number-of-k-sum-pairs/

class MaxNumberOfKSumPairs
{
public:
	// 132 ms, faster than 91.6% : 58.1 MB, less than 97.24%
	int solution(vector<int> nums, int k) {
		sort(begin(nums), end(nums));

		int st = 0, end = nums.size() - 1, cnt = 0;

		while (st < end)
		{
			if (nums[st] + nums[end] == k)
				cnt++, st++, end--;
			else if (nums[st] + nums[end] < k)
				st++;
			else
				end--;
		}
		return cnt;
	}
	vector<int> output = {
		2,
		1
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,4},
		{3,1,3,4,3}
	};
	vector<int> input2 = {
		5,
		6
	};
};