#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/flip-string-to-monotone-increasing/


class FlipStringToMonotoneIncreasing
{
public:
	// 35 ms, faster than 62.53% : 15.4 MB, less than 38.99%
	int solution(string s) {
		int n = size(s);
		vector<int> f(n, 0);

		f.back() = s.back() == '1';
		for (int i = n - 2; i >= 0; i--)
			f[i] = f[i + 1] + (s[i] == '1');

		Printer::print(f);
		int ans = n - f[0];
		int ones = 0;
		for (int i = 0; i < n; i++)
			ones += s[i] == '1', Printer::print(ones, f[i], ans), ans = min(ans, ones + n - i - 1 - f[i]);

		return ans;
	}
	vector<int> output = {
		1,
		2,
		2
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"00110",
		"010110",
		"00011000"
	};
};