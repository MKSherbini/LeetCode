#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

class BuildArrayWhereYouCanFindTheMaximumExactlyKComparisons
{
public:
	// 360 ms, faster than 5.53% : 10.3 MB, less than 23.96%
	int solution(int n, int m, int k) {
		int MOD = 1e9 + 7;
		vector mem(n, vector(m + 1, vector(k + 1, -1)));

		function<int(int, int, int)> f = [&](int i, int mx, int left) -> int {
			if (left < 0) return 0;
			if (i == n) return left == 0;
			if (mem[i][mx][left] != -1) return mem[i][mx][left];

			int ret = 0;
			for (int x = 1; x <= mx; x++) {
				ret += f(i + 1, mx, left);
				ret %= MOD;
			}
			for (int x = mx + 1; x <= m; x++) {
				ret += f(i + 1, x, left - 1);
				ret %= MOD;
			}

			return mem[i][mx][left] = ret;
		};

		return f(0, 0, k);
	}
	vector<int> output = {
		6,
		0,
		1
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		2,
		5,
		9
	};
	vector<int> input2 = {
		3,
		2,
		1
	};
	vector<int> input3 = {
		1,
		3,
		1
	};
};