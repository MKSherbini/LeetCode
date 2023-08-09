#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

class MinimizeTheMaximumDifferenceOfPairs
{
public:
	// 120 ms, faster than 98.99% : 81.1 MB, less than 82.46%
	int solution(vector<int> nums, int p) {
		int n = size(nums);
		sort(begin(nums), end(nums));

		auto valid = [&](int t) {
			int cnt = 0;
			for (size_t i = 1; i < n; i++) {
				if (nums[i] - nums[i - 1] <= t) {
					cnt++;
					i++;
				}
			}

			return cnt >= p;
		};
		int l = 0, r = nums.back() - nums[0];
		while (l < r) {
			int md = l + (r - l) / 2;

			Printer::print(md, valid(md));
			if (valid(md)) {
				r = md;
			}
			else {
				l = md + 1;
			}
		}

		return l;
	}
	vector<int> output = {
		1,
		0
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{10,1,2,7,1,3},
		{4,2,1,2}
	};
	vector<int> input2 = {
		2,
		1
	};
};