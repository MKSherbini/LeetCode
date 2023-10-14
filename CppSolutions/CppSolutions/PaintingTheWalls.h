#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/painting-the-walls/

class PaintingTheWalls
{
public:
	// 222 ms, faster than 22.31% : 115.6 MB, less than 52.57%
	int solution(vector<int> cost, vector<int> time) {
		int n = size(cost);

		vector mem(n, vector(n, -1));
		function<int(int, int)> f = [&](int i, int left) -> int {
			if (left < 0) return 0;
			if (i == n) return 5e8;
			if (mem[i][left] != -1) return mem[i][left];

			return mem[i][left] = min(f(i + 1, left), cost[i] + f(i + 1, left - 1 - time[i]));
		};

		return f(0, n - 1);
	}
	vector<int> output = {
		3,
		4
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,2},
		{2,3,4,2}
	};
	vector<vector<int>> input2 = {
		{1,2,3,2},
		{1,1,1,1}
	};
};