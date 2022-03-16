#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/shortest-path-in-binary-matrix/

class ShortestPathInBinaryMatrix
{
public:
	// 52 ms, faster than 95.93% : 19.1 MB, less than 93.65%
	int solution(vector<vector<int>> grid) {
		if (grid[0][0] || grid[grid.size() - 1][grid[0].size() - 1]) return -1;
		//Printer::print(grid);
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				if (grid[i][j])
					grid[i][j] = 0;
				else
					grid[i][j] = -1;

		queue<pair<int, int>> q;
		q.push({ 0,0 });
		grid[0][0] = 1;

		while (!q.empty()) {
			auto cur = q.front();
			//3456789 (makind)

			int dx[] = { -1, 0, -1, 0,+1,-1,+1,+1 };
			int dy[] = { -1,-1, +1,+1,+1, 0,-1, 0 };

			for (int z = 0; z < 8; z++) {
				int i = cur.first + dx[z], j = cur.second + dy[z];
				if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size()
					&& grid[i][j] == -1) {
					q.push({ i, j });
					grid[i][j] = grid[cur.first][cur.second] + 1;
				}
			}
			q.pop();
		}
		Printer::print(grid);
		return grid[grid.size() - 1][grid[0].size() - 1];
	}
	// TLE
	int solutionPrint(vector<vector<int>> grid) {
		Printer::print(grid);
		vector<vector<int>> mem(grid.size(), vector<int>(grid[0].size(), 0));
		int ans = cursePrint(grid, 0, 0, mem, mem);
		Printer::print(mem);
		return ans >= OO ? -1 : ans;
	}
	int cursePrint(vector<vector<int>>& grid, int i, int j, vector<vector<int>> vis,
		vector<vector<int>>& mem) {
		if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] || vis[i][j]) return OO;
		if (i == grid.size() - 1 && j == grid[0].size() - 1) return 1;
		vis[i][j] = 1;
		int dx[] = { -1, 0, -1, 0,+1,-1,+1,+1 };
		int dy[] = { -1,-1, +1,+1,+1, 0,-1, 0 };
		int mn = OO;
		for (int z = 0; z < 8; z++)
			mn = min(mn, cursePrint(grid, i + dx[z], j + dy[z], vis, mem));
		mem[i][j] = mn;
		Printer::printAll(i, j, mn);

		return 1 + mn;
	}
	int const OO = (int)1e7;
	vector<int> output = {
		2,
		4,
		-1,
		14,
		8,
		-1
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{0,1},{1,0}},
		{{0,0,0},{1,1,0},{1,1,0}},
		{{1,0,0},{1,1,0},{1,1,0}},
		{{0,1,1,0,0,0},{0,1,0,1,1,0},{0,1,1,0,1,0},{0,0,0,1,1,0},{1,1,1,1,1,0},{1,1,1,1,1,0}},
		{{0,0,1,1,0,0},{0,0,0,0,1,1},{1,0,1,1,0,0},{0,0,1,1,0,0},{0,0,0,0,0,0},{0,0,1,0,0,0}},
		{{0,0,0},{1,1,0},{1,1,1}}
	};
};