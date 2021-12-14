#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/max-area-of-island/

class MaxAreaOfIsland
{
public:
	// 12 ms, faster than 96.06% : 23.1 MB, less than 98.03%
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

private:
	int sink(vector<vector<int>>& arr, int i, int j) {
		if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == 0)
			return 0;

		arr[i][j] = 0;
		return 1 + sink(arr, i + 1, j)
			+ sink(arr, i - 1, j)
			+ sink(arr, i, j + 1)
			+ sink(arr, i, j - 1);
	}
};

