#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/rings-and-rods/

class RingsAndRods
{
public:
	// 0 ms, faster than 100% : 6 MB, less than 99.91%
	int solution(string rings) {
		int rods[10] = { 0 }, cnt = 0;
		for (int i = 0; i < rings.size(); i += 2)
			rods[rings[i + 1] - '0'] |=
			(rings[i] == 'R') |
			((rings[i] == 'G') << 1) |
			((rings[i] == 'B') << 2);
		for (int i = 0; i < 10; i++)
			if (rods[i] == 7) cnt++;
		return cnt;
	}
	vector<int> output = {
		1,
		1,
		0,
	};
	vector<string> input1 = {
		"B0B6G0R6R0R6G9",
		"B0R0G0R9R0B0G0",
		"G4",
	};
};

