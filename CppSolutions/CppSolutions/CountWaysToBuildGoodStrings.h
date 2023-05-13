#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-ways-to-build-good-strings/

class CountWaysToBuildGoodStrings
{
public:
	// 7 ms, faster than 97.71% : 12.3 MB, less than 62.75%
	int solution(int low, int high, int zero, int one) {
		vector<long long> mem(high + 1, 0);
		const int MOD = 1e9 + 7;
		int ans = 0;
		mem[0] = 1;
		for (int i = 1; i < high + 1; i++) {
			if (i - zero >= 0)
				mem[i] += mem[i - zero], mem[i] %= MOD;
			if (i - one >= 0)
				mem[i] += mem[i - one], mem[i] %= MOD;

			if (i >= low)
				ans += mem[i], ans %= MOD;

		}
		Printer::print(mem);

		return ans;
	}

	// WA????
	int solution2(int low, int high, int zero, int one) {
		vector<long long> mem(high + 1, -1);
		const int MOD = 1e9 + 7;
		int ans = 0;
		function<long long(int)> f = [&](int i)-> long long {
			if (i < 0) return 0;
			if (i == 0) return 1;
			if (mem[i] != -1) return mem[i];
			long long ret = f(i - zero);
			ret += f(i - one);
			ret %= MOD;

			if (i >= low && i <= high) ans += ret, ans %= MOD;

			return mem[i] = ret;
		};
		f(high);
		//Printer::print(mem);

		return ans;
	}
	vector<int> output = {
		8,
		5,
		797774039
	};

	static constexpr int const& inputs = 4;
	vector<int> input1 = {
		3,
		2,
		50000
	};
	vector<int> input2 = {
		3,
		3,
		100000
	};
	vector<int> input3 = {
		1,
		1,
		2
	};
	vector<int> input4 = {
		1,
		2,
		3
	};
};