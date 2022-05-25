#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reshape-the-matrix/

class ReshapeTheMatrix
{
public:
	// 7 ms, faster than 96.43% : 10.5 MB, less than 94.44%
	vector<vector<int>> solution(vector<vector<int>> mat, int r, int c) {
		if (r * c != mat.size() * mat[0].size()) return mat;
		vector<vector<int>> ans(r, vector<int>(c));
		int k = 0;
		for (size_t i = 0; i < mat.size(); i++)
			for (size_t j = 0; j < mat[0].size(); j++)
				ans[k / c][k % c] = mat[i][j], k++;

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{1,2,3,4}},
		{{1,2},{3,4}}
	};
	static constexpr int const& inputs = 3;
	vector<vector<vector<int>>> input1 = {
		{{1,2},{3,4}},
		{{1,2},{3,4}}
	};
	vector<int> input2 = {
		1,
		2
	};
	vector<int> input3 = {
		4,
		4
	};
};