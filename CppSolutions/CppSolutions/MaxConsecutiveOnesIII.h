#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/max-consecutive-ones-iii/

class MaxConsecutiveOnesIII
{
public:
	// 37 ms, faster than 92.49% : 55.4 MB, less than 62.36%
	int solution(vector<int> nums, int k) {
		int n = size(nums);
		int ones = 0;
		int i = 0;
		int ans = 0;
		for (int j = 0; j < n; j++) {
			if (!nums[j]) {
				if (k) {
					--k;
				}
				else {
					while (nums[i]) {
						++i;
					}
					++i;
				}
			}
			ans = max(ans, j - i + 1);
			Printer::print(i, j, k);
		}

		return ans;
	}
	vector<int> output = {
		6,
		10
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,1,1,0,0,0,1,1,1,1,0},
		{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}
	};
	vector<int> input2 = {
		2,
		3
	};
};