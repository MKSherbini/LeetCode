#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class ShortestPathInAGridWithObstaclesElimination
{
public:
	// WA
	int solution(vector<vector<int>> grid, int k) {
		int n = size(grid), m = size(grid[0]);
		queue<tuple<int, int, int, int>> q;
		q.push({ 0, 0, 0, k });

		while (!q.empty()) {
			auto& cur = q.front();
			int x = get<0>(cur);
			int y = get<1>(cur);
			int d = get<2>(cur);
			int left = get<3>(cur);
			q.pop();

			if (grid[x][y] == 1 || grid[x][y] <= -1000) --left;
			if (left < 0) continue;
			if (grid[x][y] < 0 &&
				((grid[x][y] <= -1000 && -grid[x][y] - 1000 >= left) ||
					(grid[x][y] > -1000 && -grid[x][y] >= left))) continue;
			grid[x][y] = -left - (grid[x][y] == 1 || grid[x][y] <= -1000 ? 1000 : 0);
			Printer::print(x, y, d, left);

			if (x == n - 1 && y == m - 1) return d;

			int dx[] = { 1,-1,0,0 };
			int dy[] = { 0,0,1,-1 };

			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i], yy = y + dy[i];
				if (valid(xx, n) && valid(yy, m))
					q.push({ xx, yy, d + 1, left });
			}
		}

		return -1;
	}
	bool valid(int x, int n) {
		return x >= 0 && x < n;
	}

	// 35 ms, faster than 89.57% : 15.6 MB, less than 76.92%
	int solution2(vector<vector<int>> grid, int k) {
		int n = size(grid), m = size(grid[0]);
		queue<tuple<int, int, int, int>> q;
		vector<vector<int>> vis(n, vector<int>(m, -1));
		q.push({ 0, 0, 0, k });

		while (!q.empty()) {
			auto& cur = q.front();
			int x = get<0>(cur);
			int y = get<1>(cur);
			int d = get<2>(cur);
			int left = get<3>(cur);
			q.pop();

			if (grid[x][y] == 1) --left;
			if (left < 0) continue;
			if (vis[x][y] != -1 && vis[x][y] >= left)
				continue;
			vis[x][y] = left;
			// Printer::print(x, y, d, left);

			if (x == n - 1 && y == m - 1) return d;

			int dx[] = { 1,-1,0,0 };
			int dy[] = { 0,0,1,-1 };

			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i], yy = y + dy[i];
				if (valid(xx, n) && valid(yy, m))
					q.push({ xx, yy, d + 1, left });
			}
		}

		return -1;
	}

	vector<int> output = {
		6,
		11,
		-1
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}},
		{{0,0,0},{1,1,0},{0,0,0},{0,1,1},{1,1,1},{0,0,0}},
		{{0,1,1},{1,1,1},{1,0,0}}
	};
	vector<int> input2 = {
		1,
		1,
		1
	};
};