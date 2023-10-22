#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-score-of-a-good-subarray/

class MaximumScoreOfAGoodSubarray
{
public:
	// 207 ms, faster than 38.82% : 98.3 MB, less than 42.76%
	int solution(vector<int> nums, int k) {
		int n = size(nums);

		auto f = [&](int k) {
			vector<int> r(n - k), l(k);
			int cur = INT_MAX;
			for (int i = k; i < n; i++) {
				cur = min(cur, nums[i]);
				r[i - k] = cur;
			}
			cur = INT_MAX;
			for (int i = k - 1; i >= 0; i--) {
				cur = min(cur, nums[i]);
				l[i] = cur;
			}
			Printer::print(l, r);
			int ans = 0;
			for (int j = 0; j < size(r); j++) {
				cur = r[j];
				int i = lower_bound(begin(l), end(l), cur) - begin(l);
				Printer::print(i, j);
				int size = (k + j) - i + 1;
				ans = max(ans, cur * size);
			}
			return ans;
		};

		int ans = f(k);
		reverse(begin(nums), end(nums));
		return max(ans, f(n - k - 1));
	}
	vector<int> output = {
		15,
		20
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,4,3,7,4,5},
		{5,5,4,5,4,1,1,1}
	};
	vector<int> input2 = {
		3,
		0
	};
};