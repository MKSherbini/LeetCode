#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-closed-islands/

class NumberOfClosedIslands
{
public:
	// 16 ms, faster than 43.87% : 11.3 MB, less than 19.77%
	int solution(vector<vector<int>> grid) {
		int ans = 0, c = 2;
		Printer::print(grid);
		for (size_t i = 0; i < size(grid); i++) {
			for (size_t j = 0; j < size(grid[0]); j++) {
				if (grid[i][j] == 0 && f(grid, i, j, c)) ans++;
			}
		}
		Printer::print(grid);

		return ans;
	}
	bool f(vector<vector<int>>& grid, int i, int j, int x) {
		if (!valid(i, size(grid)) || !valid(j, size(grid[0]))) return false;
		if (grid[i][j]) return true;
		grid[i][j] = x;

		const vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
		bool ret = 1;
		for (auto [dx, dy] : dir)
			ret &= f(grid, i + dx, j + dy, x);

		return ret;
	}
	bool valid(int x, int n) {
		return x >= 0 && x < n;
	}

	vector<int> output = {
		2,
		1,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}},
		{{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}},
		{{1,1,1,1,1,1,1},{1,0,0,0,0,0,1},{1,0,1,1,1,0,1},{1,0,1,0,1,0,1},{1,0,1,1,1,0,1},{1,0,0,0,0,0,1},{1,1,1,1,1,1,1}}
	};
};