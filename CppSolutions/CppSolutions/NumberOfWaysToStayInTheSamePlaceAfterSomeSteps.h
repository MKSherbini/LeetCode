#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/?envType=daily-question&envId=2023-10-15

class NumberOfWaysToStayInTheSamePlaceAfterSomeSteps
{
public:
	// 23 ms, faster than 51.3% : 10.4 MB, less than 61.25%
	int solution(int steps, int arrLen) {
		if (arrLen > steps / 2 + 1) {
			arrLen = steps / 2 + 1;
		}

		const int MOD = 1e9 + 7;
		vector mem(arrLen, vector(steps + 1, -1));
		function<int(int, int)> f = [&](int i, int left) -> int {
			if (i == arrLen || i == -1) return 0;
			if (left == 0) return mem[i][left] = i == 0;
			if (mem[i][left] != -1) return mem[i][left];

			int ret = f(i + 1, left - 1);
			ret += f(i - 1, left - 1);
			ret %= MOD;
			ret += f(i, left - 1);
			ret %= MOD;
			return mem[i][left] = ret;
		};
		f(0, steps);
		Printer::print(mem);

		return f(0, steps);
	}
	vector<int> output = {
		4,
		2,
		8
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		3,
		2,
		4
	};
	vector<int> input2 = {
		2,
		4,
		2
	};
};