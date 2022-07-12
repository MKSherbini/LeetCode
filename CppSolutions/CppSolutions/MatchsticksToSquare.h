#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/matchsticks-to-square/

class MatchsticksToSquare
{
public:
	// 444 ms, faster than 46.31% : 35.7 MB, less than 11.07%
	bool solution(vector<int> matchsticks) {
		int side = accumulate(begin(matchsticks), end(matchsticks), 0) / 4;
		int sz = (1 << size(matchsticks));
		vector<int> mem(sz, -1);
		return f(matchsticks, mem, sz - 1, 0, side, 0, 0);
	}
	bool f(vector<int>& matchsticks, vector<int>& mem, int goal, int taken, int sideSize, int sides, int len) {
		Printer::print(taken);
		if (sides == 4) return taken == goal;
		if (mem[taken] != -1) return mem[taken];

		int ret = false;
		for (int i = 0; i < size(matchsticks); i++)
		{
			int vis = (taken & (1 << i));
			if (!vis) {
				int newLen = len + matchsticks[i];
				if (newLen < sideSize)
					ret |= f(matchsticks, mem, goal, taken | (1 << i), sideSize, sides, len + matchsticks[i]);
				if (ret) break;
				if (newLen == sideSize)
					ret |= f(matchsticks, mem, goal, taken | (1 << i), sideSize, sides + 1, 0);
				if (ret) break;
			}
		}
		return mem[taken] = ret;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,1,2,2,2},
		{3,3,3,3,4}
	};
};