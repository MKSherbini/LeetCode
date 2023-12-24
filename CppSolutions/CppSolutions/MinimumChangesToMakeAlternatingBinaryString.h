#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

class MinimumChangesToMakeAlternatingBinaryString
{
public:
	// 0 ms, faster than 100% : 7.2 MB, less than 98.52%
	int solution(string s) {
		auto f = [&](bool nxt) {
			int ret = 0;
			for (auto c : s) {
				if (c != nxt + 48) ret++;
				nxt = !nxt;
			}
			return ret;
		};

		return min(f(0), f(1));
	}
	vector<int> output = {
		1,
		0,
		2
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"0100",
		"10",
		"1111"
	};
};