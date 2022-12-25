#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/domino-and-tromino-tiling/

class DominoAndTrominoTiling
{
public:
	// 0 ms, faster than 100% : 5.9 MB, less than 93.27%
	int solution(int n) {
		vector<long long> mem = { 1, 2, 5, 11 };
		if (n <= 4) return mem[n - 1];
		const int MOD = 1e9 + 7;

		for (size_t i = 4; i < n; i++) {
			swap(mem[3], mem[2]);
			swap(mem[3], mem[1]);
			swap(mem[3], mem[0]);

			mem[3] = mem[2] * 2 + mem[0];
			mem[3] %= MOD;
		}

		return mem[3];
	}
	vector<int> output = {
		5,
		1
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		3,
		1
	};
};