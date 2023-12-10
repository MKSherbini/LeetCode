#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/transpose-matrix/

class TransposeMatrix
{
public:
	// 0 ms, faster than 100% : 10.9 MB, less than 84.6%
	vector<vector<int>> solution(vector<vector<int>> matrix) {
		int n = size(matrix), m = size(matrix[0]);

		vector<vector<int>> ans(m, vector<int>(n));
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				ans[j][i] = matrix[i][j];
			}
		}

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{1,4,7},{2,5,8},{3,6,9}},
		{{1,4},{2,5},{3,6}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2,3},{4,5,6},{7,8,9}},
		{{1,2,3},{4,5,6}}
	};
};