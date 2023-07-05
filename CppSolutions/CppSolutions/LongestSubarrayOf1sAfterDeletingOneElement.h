#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class LongestSubarrayOf1sAfterDeletingOneElement
{
public:
	// 31 ms, faster than 98.79% : 36.4 MB, less than 98.32%
	int solution(vector<int> nums) {
		int n = size(nums);
		int ans = 0;
		int lastLen = 0;

		for (int i = 0; i < n; i++) {
			if (!nums[i]) continue;

			int j = i;
			while (j < n && nums[j]) j++;

			int len = j - i;
			Printer::print(i, len, lastLen);

			if (i > 1 && !nums[i - 1] && nums[i - 2])
				ans = max(ans, len + lastLen);

			if (i > 0 && !nums[i - 1] || (j < n && !nums[j]))
				ans = max(ans, len);
			else
				ans = max(ans, len - 1);

			lastLen = len;
			i = j - 1;
		}

		return ans;
	}
	vector<int> output = {
		3,
		5,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,1,0,1},
		{0,1,1,1,0,1,1,0,1},
		{1,1,1}
	};
};