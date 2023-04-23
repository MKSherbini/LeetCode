#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/restore-the-array/

class RestoreTheArray
{
public:
	// 131 ms, faster than 20.93% : 40.1 MB, less than 11.05%
	int solution(string s, int k) {
		int n = size(s);
		vector mem(n, -1);
		const int MOD = 1e9 + 7;

		function<int(int)> f = [&](int i) -> int {
			if (i == n) return 1;
			if (s[i] == '0') return 0;
			if (mem[i] != -1) return mem[i];

			int ret = 0;
			long long t = 0;
			for (int j = i; j < n; ++j) {
				t = t * 10 + (s[j] - '0');
				if (t > k)
					break;
				ret += f(j + 1), ret %= MOD;
			}

			return mem[i] = ret;
		};

		return f(0);
	}
	vector<int> output = {
		1,
		0,
		8
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"1000",
		"1000",
		"1317"
	};
	vector<int> input2 = {
		10000,
		10,
		2000
	};
};