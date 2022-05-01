#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/integer-break/

class IntegerBreak
{
public:
	// 0 ms, faster than 100% : 6.2 MB, less than 48.99%
	int solution(int n) {
		if (n <= 3) return n - 1;
		vector<int> mem(n + 1, -1);
		auto ret = curse(n, mem);
		Printer::print(mem);
		return ret;
	}
	int curse(int n, vector<int>& mem) {
		if (mem[n] != -1) return mem[n];

		int ret = 1;
		for (int i = 1; i <= n; i++)
			ret = max(ret, i * curse(n - i, mem));

		return mem[n] = ret;
	}
	vector<int> output = {
		1,
		36
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		2,
		10
	};
};