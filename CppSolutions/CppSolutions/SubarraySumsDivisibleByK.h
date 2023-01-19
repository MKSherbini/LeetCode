#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/subarray-sums-divisible-by-k/

class SubarraySumsDivisibleByK
{
public:
	// 36 ms, faster than 98.69% : 30 MB, less than 97.21%
	int solution(vector<int> nums, int k) {
		int n = size(nums);
		vector<int> mods(k, 0);
		++mods[0];

		int ans = 0, pre = 0;
		for (size_t i = 0; i < n; i++) {
			pre = (pre + nums[i] % k + k) % k;
			ans += mods[pre];
			++mods[pre];
		}

		return ans;
	}
	vector<int> output = {
		7,
		0
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{4,5,0,-2,-3,1},
		{5}
	};
	vector<int> input2 = {
		5,
		9
	};
};