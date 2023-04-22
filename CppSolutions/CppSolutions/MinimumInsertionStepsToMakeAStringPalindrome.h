#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class MinimumInsertionStepsToMakeAStringPalindrome
{
public:
	// 153 ms, faster than 5.54% : 28.4 MB, less than 50.59%
	int solution(string s) {
		int n = size(s);
		vector mem(n, vector<int>(n, -1));

		function<int(int, int)> f = [&](int i, int j) -> int {
			if (i >= j) return 0;

			if (mem[i][j] != -1) return mem[i][j];

			int ret = min(f(i + 1, j), f(i, j - 1)) + 1;
			if (s[i] == s[j])
				ret = min(ret, f(i + 1, j - 1));

			return mem[i][j] = ret;
		};

		return f(0, n - 1);
	}
	vector<int> output = {
		0,
		2,
		5
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"zzazz",
		"mbadm",
		"leetcode"
	};
};