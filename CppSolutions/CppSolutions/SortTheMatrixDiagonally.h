#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sort-the-matrix-diagonally/

class SortTheMatrixDiagonally
{
public:
	// 3 ms, faster than 99.87% : 9.1 MB, less than 79.14%
	vector<vector<int>> solution(vector<vector<int>> mat) {
		int n = size(mat);
		int m = size(mat[0]);

		for (int i = n - 1; i >= 0; i--)
		{
			vector<int> v;
			int idx = 0;
			for (int j = 0; j < min(m, n - i); j++)
				v.push_back(mat[i + j][j]);
			sort(begin(v), end(v));
			for (int j = 0; j < min(m, n - i); j++)
			{
				Printer::print(j + i, j);
				mat[i + j][j] = v[idx++];
			}
		}

		for (int j = 1; j < m; j++)
		{
			vector<int> v;
			int idx = 0;
			for (int i = 0; i < min(n, m - j); i++)
				v.push_back(mat[i][j + i]);
			sort(begin(v), end(v));
			for (int i = 0; i < min(n, m - j); i++)
			{
				Printer::print(i, j + i);
				mat[i][j + i] = v[idx++];
			}
		}

		return mat;
	}
	vector<vector<vector<int>>> output = {
		{{1,1,1,1},{1,2,2,2},{1,2,3,3}},
		{{5,17,4,1,52,7},{11,11,25,45,8,69},{14,23,25,44,58,15},{22,27,31,36,50,66},{84,28,75,33,55,68}},
		{{37,98,82,45,42}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{3,3,1,1},{2,2,1,2},{1,1,1,2}},
		{{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}},
		{{37,98,82,45,42}}
	};
};