#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class MinimumFlipsToMakeAOrBEqualToC
{
public:
	// 0 ms, faster than 100% : 5.9 MB, less than 93.59%
	int solution(int a, int b, int c) {
		int ans = 0;
		while (c) {
			bool x = a & 1, y = b & 1, res = c & 1;

			a >>= 1;
			b >>= 1;
			c >>= 1;

			if ((x || y) == res) continue;

			if (res)
				ans++;
			else
				ans += x + y;
		}

		while (a) {
			if (a & 1)
				ans++;
			a >>= 1;
		}

		while (b) {
			if (b & 1)
				ans++;
			b >>= 1;
		}

		return ans;
	}
	vector<int> output = {
		3,
		1,
		0
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		2,
		4,
		1
	};
	vector<int> input2 = {
		6,
		2,
		2
	};
	vector<int> input3 = {
		5,
		7,
		3
	};
};