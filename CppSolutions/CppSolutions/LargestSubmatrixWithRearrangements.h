#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/largest-submatrix-with-rearrangements/

class LargestSubmatrixWithRearrangements
{
public:
	// 136 ms, faster than 93.75% : 66.1 MB, less than 96.02%
	int solution(vector<vector<int>> matrix) {
		int n = size(matrix), m = size(matrix[0]);
		for (size_t j = 0; j < m; j++) {
			for (size_t i = 1; i < n; i++) {
				if (matrix[i][j])
					matrix[i][j] += matrix[i - 1][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			sort(begin(matrix[i]), end(matrix[i]), greater());
			for (int j = 0; j < m; j++) {
				ans = max(ans, (j + 1) * matrix[i][j]);
			}
		}

		return ans;
	}
	vector<int> output = {
		4,
		3,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{0,0,1},{1,1,1},{1,0,1}},
		{{1,0,1,0,1}},
		{{1,1,0},{1,0,1}}
	};
};