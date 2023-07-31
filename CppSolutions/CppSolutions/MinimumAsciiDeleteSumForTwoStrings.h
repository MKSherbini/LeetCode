#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class MinimumAsciiDeleteSumForTwoStrings
{
public:
	// 152 ms, faster than 5.11% : 15.4 MB, less than 14.89%
	int solution(string s1, string s2) {
		int n = size(s1), m = size(s2);

		vector mem(n + 1, vector(m + 1, -1));
		function<int(int, int)> f = [&](int i, int j) -> int {
			if (i >= n && j >= m) {
				return 0;
			}

			if (i < n && j < m && mem[i][j] != -1) return mem[i][j];
			int ret = INT_MAX;

			if (i < n && j < m && s1[i] == s2[j])
				ret = min(ret, f(i + 1, j + 1));

			if (j < m)
				ret = min(ret, s2[j] + f(i, j + 1));
			if (i < n)
				ret = min(ret, s1[i] + f(i + 1, j));

			return mem[i][j] = ret;
		};

		return f(0, 0);
	}
	vector<int> output = {
		231,
		403
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"sea",
		"delete"
	};
	vector<string> input2 = {
		"eat",
		"leet"
	};
};