#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-average-difference/

class MinimumAverageDifference
{
public:
	// 118 ms, faster than 97.61% : 84.6 MB, less than 43.62%
	int solution(vector<int> nums) {
		int n = size(nums);
		int ans = 0, mn = INT_MAX;

		vector<long long> pre(begin(nums), end(nums));

		for (size_t i = 1; i < n; i++)
			pre[i] += pre[i - 1];

		for (size_t i = 0; i < n; i++) {
			long long d1 = pre[i] / (i + 1);
			long long d2 = (n - i - 1) == 0 ? 0 : (pre[n - 1] - pre[i]) / (n - i - 1);
			long long dif = abs(d1 - d2);
			if (dif < mn)
				mn = dif, ans = i;
		}

		return ans;
	}
	vector<int> output = {
		3,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,5,3,9,5,3},
		{0}
	};
};