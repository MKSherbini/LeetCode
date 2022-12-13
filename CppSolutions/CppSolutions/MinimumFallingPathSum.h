#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-falling-path-sum/

class MinimumFallingPathSum
{
public:
	// 14 ms, faster than 94.54% : 10.1 MB, less than 67.65%
	int solution(vector<vector<int>> matrix) {
		int n = size(matrix), m = size(matrix[0]);
		vector<vector<int>> mem(matrix);

		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				int mn = INT_MAX;
				mn = mem[i + 1][j];
				if (j > 0)
					mn = min(mem[i + 1][j - 1], mn);
				if (j < m - 1)
					mn = min(mem[i + 1][j + 1], mn);

				mem[i][j] += mn;
			}
		}

		Printer::print(matrix);
		Printer::print(mem);

		return *min_element(begin(mem[0]), end(mem[0]));
	}
	vector<int> output = {
		13,
		-59,
		-36
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{2,1,3},{6,5,4},{7,8,9}},
		{{-19,57},{-40,-5}},
		{{100,-42,-46,-41},{31,97,10,-10},{-58,-51,82,89},{51,81,69,-51}}
	};
};