#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-islands/

class NumberOfIslands
{
public:
	// 32 ms, faster than 94.55% : 12.1 MB, less than 97.29%
	int solution(vector<vector<char>> grid) {
		int mx = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1')
					mx++, sink(grid, i, j);
			}
		}
		return mx;
	}
	void sink(vector<vector<char>>& arr, int i, int j) {
		if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == '0')
			return;

		arr[i][j] = '0';
		sink(arr, i + 1, j), sink(arr, i - 1, j), sink(arr, i, j + 1), sink(arr, i, j - 1);
	}

	// 32 ms, faster than 94.55% : 12.1 MB, less than 97.29%
	int solution2(vector<vector<char>> grid) {
		int mx = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				mx += sink2(grid, i, j) > 0;
			}
		}
		return mx;
	}
	int sink2(vector<vector<char>>& arr, int i, int j) {
		if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == '0')
			return 0;

		arr[i][j] = '0';
		return 1 + sink2(arr, i + 1, j)
			+ sink2(arr, i - 1, j)
			+ sink2(arr, i, j + 1)
			+ sink2(arr, i, j - 1);
	}

	vector<int> output = {
		1,
		3
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<char>>> input1 = {
		{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}},
		{{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}}
	};
};