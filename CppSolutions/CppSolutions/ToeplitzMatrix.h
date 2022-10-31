#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/toeplitz-matrix/

class ToeplitzMatrix
{
public:
	// 17 ms, faster than 88.89% : 17.3 MB, less than 98.97%
	bool solution(vector<vector<int>> matrix) {
		int n = size(matrix), m = size(matrix[0]);
		for (size_t i = 1; i < n; i++)
		{
			for (size_t j = 1; j < m; j++)
			{
				if (matrix[i][j] != matrix[i - 1][j - 1]) return false;
			}
		}
		return true;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2,3,4},{5,1,2,3},{9,5,1,2}},
		{{1,2},{2,2}}
	};
};