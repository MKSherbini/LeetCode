#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/decode-ways/

class DecodeWays
{
public:
	// 0 ms, faster than 100% : 6.1 MB, less than 92.61%
	int solution(string s) {
		vector<int> mem(s.size(), -1);
		auto ret = curse(s, mem, 0);
		Printer::print(mem);
		return max(0, ret);
	}
	int curse(string& s, vector<int>& mem, int i) {
		if (i == s.size()) return 1;
		if (s[i] == '0') return 0;
		if (mem[i] != -1) return mem[i];

		int ret = 0;
		if (i + 1 < s.size() && stoi(s.substr(i, 2)) <= 26)
			ret += curse(s, mem, i + 2);
		ret += curse(s, mem, i + 1);

		return mem[i] = ret;
	}
	vector<int> output = {
		2,
		3,
		0,
		2,
		1,
		1
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"12",
		"226",
		"606",
		"3546846851546",
		"10",
		"2101"
	};
};