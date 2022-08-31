#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/pacific-atlantic-water-flow/

class PacificAtlanticWaterFlow
{
public:
	// 35 ms, faster than 99.36% : 18.2 MB, less than 63.01%
	vector<vector<int>> solution(vector<vector<int>> heights) {
		int n = size(heights);
		int m = size(heights[0]);
		vector<vector<int>> vis(n, vector(m, 0));
		vector<vector<int>> ans;
		for (size_t i = 0; i < n; i++)
		{
			f(heights, vis, ans, i, 0, 1);
			f(heights, vis, ans, i, m - 1, 2);
		}

		for (size_t j = 0; j < m; j++)
		{
			f(heights, vis, ans, 0, j, 1);
			f(heights, vis, ans, n - 1, j, 2);
		}
		Printer::print(vis);
		return ans;
	}
	void f(vector<vector<int>>& heights, vector<vector<int>>& vis, vector<vector<int>>& ans, int i, int j, int ocean) {
		Printer::print(i, j, ocean, vis[i][j]);
		if ((vis[i][j] & ocean))
			return;
		else
		{
			vis[i][j] |= ocean;
			if (vis[i][j] == 3) ans.push_back({ i,j });
		}

		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };

		for (int z = 0; z < 4; z++)
		{
			int x = i + dx[z], y = j + dy[z];
			if (isValid(x, size(heights)) && isValid(y, size(heights[0]))
				&& heights[x][y] >= heights[i][j])
				f(heights, vis, ans, x, y, ocean);
		}
	}
	int8_t isValid(int x, int sz) {
		return x >= 0 && x < sz;
	}

	vector<vector<vector<int>>> output = {
		{{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}},
		{{0,0}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}},
		{{1}}
	};
};