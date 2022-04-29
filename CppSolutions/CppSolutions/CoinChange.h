#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/coin-change/

class CoinChange
{
public:
	// 158 ms, faster than 28.28% : 45.4 MB, less than 18.07%
	int solution(vector<int> coins, int amount) {
		vector<vector<int>> mem(coins.size(), vector<int>(amount + 1, -1));
		auto ret = curse(coins, mem, amount, 0);
		return ret >= OO ? -1 : ret;
	}
	int curse(vector<int>& nums, vector<vector<int>>& mem, int sum, int i) {
		if (sum == 0) return 0;
		if (i == nums.size() || sum < 0) return OO;
		if (mem[i][sum] != -1) return mem[i][sum];

		int ret = curse(nums, mem, sum, i + 1);
		ret = min(ret, 1 + curse(nums, mem, sum - nums[i], i + 1));
		ret = min(ret, 1 + curse(nums, mem, sum - nums[i], i));

		return mem[i][sum] = ret;
	}
	const int OO = (int)1e8;
	vector<int> output = {
		3,
		-1,
		0
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,5},
		{2},
		{1}
	};
	vector<int> input2 = {
		11,
		3,
		0
	};
};