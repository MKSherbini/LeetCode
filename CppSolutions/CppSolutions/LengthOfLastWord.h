#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/length-of-last-word/

class LengthOfLastWord
{
public:
	// 0 ms, faster than 100% : 6.4 MB, less than 99.41%
	int solution(string s) {
		auto it = s.rbegin();

		while (*it == ' ') {
			it++;
			if (it == rend(s)) return 0;
		}

		int cnt = 0;

		while (*it != ' ') {
			cnt++, it++;
			if (it == rend(s)) break;
		}

		return cnt;
	}
	vector<int> output = {
		5,
		4,
		6,
		1,
		0,
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"Hello World",
		"   fly me   to   the moon  ",
		"luffy is still joyboy",
		"a",
		"   ",
	};
};

