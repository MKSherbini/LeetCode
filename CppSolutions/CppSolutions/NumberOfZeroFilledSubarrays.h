#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-zero-filled-subarrays/

class NumberOfZeroFilledSubarrays
{
public:
	// 144 ms, faster than 97.59% : 107.4 MB, less than 86.43%
	long long solution(vector<int> nums) {
		long long ans = 0;

		int n = 0;
		for (auto x : nums) {
			if (x == 0) n++;
			else ans += n == 0 ? 0 : 1LL * n * (n + 1) / 2, n = 0;
		}

		return ans + (n == 0 ? 0 : 1LL * n * (n + 1) / 2);
	}
	vector<int> output = {
		6,
		9,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,3,0,0,2,0,0,4},
		{0,0,0,2,0,0},
		{2,10,2019}
	};
};