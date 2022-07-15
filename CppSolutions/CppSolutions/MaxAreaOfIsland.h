#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/max-area-of-island/

class MaxAreaOfIsland
{
public:
	// 11 ms, faster than 99.5% : 23.1 MB, less than 89.29%
	int solution(vector<vector<int>>& grid) {
		int mx = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				mx = max(mx, sink(grid, i, j));
			}
		}
		return mx;
	}

	int sink(vector<vector<int>>& arr, int i, int j) {
		if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == 0)
			return 0;

		arr[i][j] = 0;
		return 1 + sink(arr, i + 1, j)
			+ sink(arr, i - 1, j)
			+ sink(arr, i, j + 1)
			+ sink(arr, i, j - 1);
	}
	vector<int> output = {
		6,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}},
		{{0,0,0,0,0,0,0,0}}
	};
};