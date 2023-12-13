#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/special-positions-in-a-binary-matrix/

class SpecialPositionsInABinaryMatrix
{
public:
	// 14 ms, faster than 79.47% : 13.1 MB, less than 70.53%
	int solution(vector<vector<int>> mat) {
		int n = size(mat), m = size(mat[0]);
		vector v(n, -1);
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				if (mat[i][j] == 1 && v[i] == -1)
					v[i] = j;
				else if (mat[i][j] == 1) {
					v[i] = -1;
					break;
				}
			}
		}

		//Printer::print(mat);
		//Printer::print(v);
		int ans = 0;
		for (size_t i = 0; i < n; i++) {
			if (v[i] == -1) continue;
			int c = 0;
			for (size_t j = 0; j < n; j++) {
				c += mat[j][v[i]] == 1;
				//Printer::print(v[i], j, mat[i][v[i]] == 1, c);
			}
			if (c == 1) ans++;
		}

		return ans;
	}
	vector<int> output = {
		1,
		3,
		2,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,0,0},{0,0,1},{1,0,0}},
		{{1,0,0},{0,1,0},{0,0,1}},
		{{0,0,1,0},{0,0,0,0},{0,0,0,0},{0,1,0,0}},
		{{0,0},{0,0},{0,1}},
	};
};