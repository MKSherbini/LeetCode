#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

class ArithmeticSlicesIiSubsequence
{
public:
	// 728 ms, faster than 89.31% : 154.6 MB, less than 65.65%
	int solution(vector<int> nums) {
		int  n = size(nums);
		vector<unordered_map<long long, long long>> v(n);
		long long ans = 0;

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				long long dif = (long long)nums[i] - nums[j];

				++v[i][dif];
				if (v[j].contains(dif)) {
					v[i][dif] += v[j][dif];
					ans += v[j][dif];
				}
			}
		}
		Printer::print(v);

		return ans;
	}
	vector<int> output = {
		7,
		16
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,4,6,8,10},
		{7,7,7,7,7}
	};
};