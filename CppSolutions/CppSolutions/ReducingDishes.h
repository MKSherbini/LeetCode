#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reducing-dishes/

class ReducingDishes
{
public:
	// 47 ms, faster than 38.08% : 20.7 MB, less than 54.51%
	int solution(vector<int> satisfaction) {
		sort(begin(satisfaction), end(satisfaction));
		int n = size(satisfaction);
		vector mem(n, vector(n, -1));
		return f(satisfaction, mem, 0, 0);
	}
	int f(vector<int>& satisfaction, vector<vector<int>>& mem, int i, int c) {
		if (i == size(satisfaction)) return 0;
		if (mem[i][c] != -1)return mem[i][c];

		int ret = 0;
		ret = max(ret, f(satisfaction, mem, i + 1, c + 1) + (c + 1) * satisfaction[i]);
		ret = max(ret, f(satisfaction, mem, i + 1, c));
		return mem[i][c] = ret;
	}
	vector<int> output = {
		14,
		20,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{-1,-8,0,5,-9},
		{4,3,2},
		{-1,-4,-5}
	};
};