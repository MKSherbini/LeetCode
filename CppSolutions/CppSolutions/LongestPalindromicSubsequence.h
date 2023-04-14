#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-palindromic-subsequence/

class LongestPalindromicSubsequence
{
public:
	// 339 ms, faster than 5.06% : 72.9 MB, less than 63.49%
	int solution(string s) {
		int n = size(s);
		vector<vector<int>> mem(n, vector<int>(n, -1));
		return f(mem, s, 0, n - 1);
	}
	int f(vector<vector<int>>& mem, string& s, int i, int j) {
		if (i == j) return 1;
		if (i > j) return 0;

		if (mem[i][j] != -1) return mem[i][j];

		int ret = 0;
		ret = max(ret, f(mem, s, i, j - 1));
		ret = max(ret, f(mem, s, i + 1, j));
		if (s[i] == s[j])
			ret = max(ret, 2 + f(mem, s, i + 1, j - 1));

		return mem[i][j] = ret;
	}
	vector<int> output = {
		4,
		5
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"bbbab",
		"aabaa"
	};
};