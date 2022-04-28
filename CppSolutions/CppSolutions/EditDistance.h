#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/edit-distance/

class EditDistance
{
public:
	// 18 ms, faster than 53% : 8.9 MB, less than 64.49%
	int solution(string word1, string word2) {
		vector<vector<int>> mem(word1.size(), vector<int>(word2.size(), -1));
		auto ret = curse(word1, word2, mem, 0, 0);
		Printer::print(mem);
		return ret;
	}
	int curse(string& s1, string& s2, vector<vector<int>>& mem, int i, int j) {
		if (i >= s1.size()) return s2.size() - j;
		if (j >= s2.size()) return s1.size() - i;
		if (mem[i][j] != -1) return mem[i][j];
		int ret = OO;
		if (s1[i] == s2[j])
			ret = curse(s1, s2, mem, i + 1, j + 1);

		ret = min(ret, 1 + curse(s1, s2, mem, i + 1, j));
		ret = min(ret, 1 + curse(s1, s2, mem, i, j + 1));
		ret = min(ret, 1 + curse(s1, s2, mem, i + 1, j + 1));
		return mem[i][j] = ret;
	}
	const int OO = (int)1e8;
	vector<int> output = {
		3,
		5
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"horse",
		"intention"
	};
	vector<string> input2 = {
		"ros",
		"execution"
	};
};