#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-common-subsequence/

class LongestCommonSubsequence
{
public:
	// 508 ms, faster than 15.2% : 10.7 MB, less than 12.73%
	int solution(string text1, string text2) {
		vector<vector<int>> mem(text1.size(), vector<int>(text2.size(), -1));
		auto ret = curse(text1, text2, mem, 0, 0);
		Printer::print(mem);
		return ret;
	}
	int curse(string& s1, string& s2, vector<vector<int>>& mem, int i, int j) {
		if (i >= s1.size() || j >= s2.size()) return 0;
		if (mem[i][j] != -1) return mem[i][j];
		int ret = 0;
		if (s1[i] == s2[j])
			ret = 1 + curse(s1, s2, mem, i + 1, j + 1);

		ret = max(ret, curse(s1, s2, mem, i + 1, j));
		ret = max(ret, curse(s1, s2, mem, i, j + 1));
		return mem[i][j] = ret;
	}
	const int OO = (int)1e8;
	vector<int> output = {
		3,
		3,
		0
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"abcde",
		"abc",
		"abc"
	};
	vector<string> input2 = {
		"ace",
		"abc",
		"def"
	};
};