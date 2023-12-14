#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

class DifferenceBetweenOnesAndZerosInRowAndColumn
{
public:
	// 177 ms, faster than 93.59% : 117.4 MB, less than 76.35%
	vector<vector<int>> solution(vector<vector<int>> grid) {
		int n = size(grid), m = size(grid[0]);
		vector ans(n, vector(m, 0));
		vector onesi(n, 0), onesj(m, 0);
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) { 
				onesi[i] += grid[i][j] == 1;
				onesj[j] += grid[i][j] == 1;
			}
		}

		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				ans[i][j] = 2 * onesi[i] + 2 * onesj[j] - n - m;
			}
		}

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{0,0,4},{0,0,4},{-2,-2,2}},
		{{5,5,5},{5,5,5}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{0,1,1},{1,0,1},{0,0,1}},
		{{1,1,1},{1,1,1}}
	};
};