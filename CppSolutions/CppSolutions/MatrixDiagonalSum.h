#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/matrix-diagonal-sum/

class MatrixDiagonalSum
{
public:
	// 11 ms, faster than 87.18% : 11.1 MB, less than 92.07%
	int solution(vector<vector<int>> mat) {
		int ans = 0;
		int n = size(mat);

		for (size_t i = 0; i < n; i++) {
			ans += mat[i][i] + mat[i][n - i - 1];
		}

		if (n % 2)
			ans -= mat[n / 2][n / 2];
		return ans;
	}
	vector<int> output = {
		25,
		8,
		5
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2,3},{4,5,6},{7,8,9}},
		{{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}},
		{{5}}
	};
};