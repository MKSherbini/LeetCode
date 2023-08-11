#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/coin-change-ii/

class CoinChangeII
{
public:
	// 7 ms, faster than 95.03% : 20 MB, less than 14.41%
	int solution(int amount, vector<int> coins) {
		int n = size(coins);
		sort(begin(coins), end(coins), greater());

		vector mem(n, vector(amount + 1, -1));
		function<int(int, int)> f = [&](int i, int left) -> int {
			if (left == 0) return 1;
			if (i >= n) return 0;
			if (mem[i][left] != -1) return mem[i][left];

			int ret = f(i + 1, left);
			if (coins[i] <= left)
				ret += f(i, left - coins[i]);

			return mem[i][left] = ret;
		};

		return f(0, amount);
	}
	vector<int> output = {
		4,
		0,
		1
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		5,
		3,
		10
	};
	vector<vector<int>> input2 = {
		{1,2,5},
		{2},
		{10}
	};
};