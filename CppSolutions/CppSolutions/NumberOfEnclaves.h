#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-enclaves/

class NumberOfEnclaves
{
public:
	// 161 ms, faster than 6.55% : 74.8 MB, less than 5.01%
	int solution(vector<vector<int>> grid) {
		int ans = 0, c;
		for (size_t i = 0; i < size(grid); i++) {
			for (size_t j = 0; j < size(grid[0]); j++) {
				if (grid[i][j] == 1 && (c = f(grid, i, j)) > 0) ans += c;
			}
		}

		return ans;
	}
	int f(vector<vector<int>>& grid, int i, int j) {
		if (!valid(i, size(grid)) || !valid(j, size(grid[0]))) return -1e6;
		if (grid[i][j] != 1) return 0;
		grid[i][j] = 2;

		const vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
		int ret = 1;
		for (auto [dx, dy] : dir)
			ret += f(grid, i + dx, j + dy);

		return ret;
	}
	bool valid(int x, int n) {
		return x >= 0 && x < n;
	}
	vector<int> output = {
		3,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}},
		{{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}}
	};
};