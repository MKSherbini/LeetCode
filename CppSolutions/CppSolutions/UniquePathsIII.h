#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/unique-paths-iii/

class UniquePathsIII
{
public:
	// 456 ms, faster than 5.1% : 243.8 MB, less than 5.1%
	int solution(vector<vector<int>> grid) {
		Printer::print(grid);
		int ret = 0;
		int si, sj;
		int cnt = 0;
		for (size_t i = 0; i < size(grid); i++)
			for (size_t j = 0; j < size(grid[0]); j++)
				if (grid[i][j] == 1)
					si = i, sj = j;
				else if (grid[i][j] == 0)
					++cnt;


		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };
		for (int d = 0; d < 4; d++)
			ret += f(grid, si + dx[d], sj + dy[d], {}, cnt);
		return ret;
	}

	int f(vector<vector<int>>& grid, int i, int j, set<pair<int, int>> row, int cnt) {
		if (!valid(i, size(grid)) || !valid(j, size(grid[0]))) return 0;
		int& cur = grid[i][j];
		if (cur == 2) return cnt == 0;
		if (cur != 0) return 0;
		if (row.count({ i, j })) return 0;
		//Printer::print(i, j);
		cur = -1;
		row.insert({ i,j });
		--cnt;
		int ret = 0;
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };
		for (int d = 0; d < 4; d++)
			ret += f(grid, i + dx[d], j + dy[d], row, cnt);

		cur = 0;
		return ret;
	}

	bool valid(int x, int n) {
		return x >= 0 && x < n;
	}
	vector<int> output = {
		2,
		4,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,0,0,0},{0,0,0,0},{0,0,2,-1}},
		{{1,0,0,0},{0,0,0,0},{0,0,0,2}},
		{{0,1},{2,0}}
	};
};