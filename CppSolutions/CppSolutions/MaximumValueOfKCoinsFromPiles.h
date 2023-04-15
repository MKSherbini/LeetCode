#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

class MaximumValueOfKCoinsFromPiles
{
public:
	// 263 ms, faster than 80.37% : 18 MB, less than 80.63%
	int solution(vector<vector<int>> piles, int k) {
		int n = size(piles);
		vector<vector<int>> mem(n, vector<int>(k + 1, -1));

		return f(piles, mem, n - 1, k);
	}
	int f(vector<vector<int>>& piles, vector<vector<int>>& mem, int i, int limit) {
		if (i < 0) return 0;
		if (mem[i][limit] != -1) return mem[i][limit];

		int ret = 0, sum = 0;
		for (int coins = 0; coins <= min((int)size(piles[i]), limit); coins++) {
			if (coins > 0) {
				sum += piles[i][coins - 1];
			}
			ret = max(ret, f(piles, mem, i - 1, limit - coins) + sum);
		}
		return mem[i][limit] = ret;
	};
	vector<int> output = {
		101,
		706
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{1,100,3},{7,8,9}},
		{{100},{100},{100},{100},{100},{100},{1,1,1,1,1,1,700}}
	};
	vector<int> input2 = {
		2,
		7
	};
};