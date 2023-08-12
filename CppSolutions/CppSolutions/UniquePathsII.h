#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/unique-paths-ii/

class UniquePathsII
{
public:
	// 0 ms, faster than 100% : 7.8 MB, less than 61.67%
	int solution(vector<vector<int>> obstacleGrid) {
		int n = size(obstacleGrid), m = size(obstacleGrid[0]);

		vector mem(n, vector(m, -1));
		function<int(int, int)> f = [&](int i, int j) -> int {
			if (i == n || j == m) return 0;
			if (obstacleGrid[i][j]) return 0;
			if (i == n - 1 && j == m - 1) return 1;
			if (mem[i][j] != -1) return mem[i][j];

			return mem[i][j] = f(i + 1, j) + f(i, j + 1);
		};

		return f(0, 0);
	}
	vector<int> output = {
		2,
		1,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{0,0,0},{0,1,0},{0,0,0}},
		{{0,1},{0,0}},
		{{0,0,0,0,0},{0,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0}}
	};
};