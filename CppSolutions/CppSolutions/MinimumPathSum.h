#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-path-sum/

class MinimumPathSum
{
public:
	// 7 ms, faster than 90.29% : 9.5 MB, less than 99.95%
	int solution(vector<vector<int>> grid) {
		int n = size(grid), m = size(grid[0]);
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				int mn = 1e7;
				if (i > 0) mn = min(mn, grid[i - 1][j]);
				if (j > 0) mn = min(mn, grid[i][j - 1]);
				grid[i][j] += mn == 1e7 ? 0 : mn;
			}
		}
		return grid[n - 1][m - 1];
	}
	vector<int> output = {
		7,
		12
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,3,1},{1,5,1},{4,2,1}},
		{{1,2,3},{4,5,6}}
	};
};