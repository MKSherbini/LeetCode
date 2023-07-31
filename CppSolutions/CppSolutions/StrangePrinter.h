#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/strange-printer/

class StrangePrinter
{
public:
	// 294 ms, faster than 13.65% : 9.5 MB, less than 41.87%
	int solution(string s) {
		int n = size(s);
		vector mem(n, vector<int>(n, -1));

		function<int(int, int)> f = [&](int l, int r) -> int {
			if (mem[l][r] != -1) {
				return mem[l][r];
			}

			mem[l][r] = n;
			int j = -1;

			for (int i = l; i < r; i++) {
				if (s[i] != s[r] && j == -1) {
					j = i;
				}

				if (j != -1) {
					mem[l][r] = min(mem[l][r], f(j, i) + f(i + 1, r));
				}
			}

			if (j == -1) {
				mem[l][r] = 1;
			}

			return mem[l][r];
		};

		return f(0, n - 1);
	}
	vector<int> output = {
		2,
		2
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"aaabbb",
		"aba"
	};
};