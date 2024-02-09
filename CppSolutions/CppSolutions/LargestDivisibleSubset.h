#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/largest-divisible-subset/

class LargestDivisibleSubset
{
public:
	// 7 ms, faster than 99.68% : 11.2 MB, less than 43.61%
	vector<int> solution(vector<int> nums) {
		int n = size(nums);
		int mxI = 0, mx = 0;
		sort(begin(nums), end(nums));
		vector<int> len(n, 1);
		for (size_t i = 1; i < n; i++) {
			for (size_t j = 0; j < i; j++) {
				if (nums[i] % nums[j] == 0) {
					len[i] = max(len[i], len[j] + 1);
					if (len[i] > mx) mx = len[i], mxI = i;
				}
			}
		}
		Printer::print(len);

		vector<int> ans;
		int lastI = mxI;
		ans.push_back(nums[lastI]);
		for (int i = mxI - 1; i >= 0; i--) {
			if (len[i] + 1 == len[lastI] && nums[lastI] % nums[i] == 0) {
				ans.push_back(nums[i]);
				lastI = i;
			}
		}
		return ans;
	}
	vector<vector<int>> output = {
		{1,2},
		{1,2,4,8}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3},
		{1,2,4,8}
	};
};