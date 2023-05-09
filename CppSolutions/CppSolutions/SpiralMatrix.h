#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/spiral-matrix/

class SpiralMatrix
{
public:
	// 0 ms, faster than 100% : 6.7 MB, less than 91.37%
	vector<int> solution(vector<vector<int>> matrix) {
		int n = size(matrix), m = size(matrix[0]);
		int i = 0, j = 0;
		int state = 0;

		vector<int> ans;
		int c = 0;
		int lvl = 0;
		while (c < n * m) {
			ans.push_back(matrix[i][j]);

			if (state == 0) {
				if (j == m - lvl - 1) i++, state++, state %= 4;
				else j++;
			}
			else if (state == 1) {
				if (i == n - lvl - 1) j--, state++, state %= 4;
				else i++;
			}
			else if (state == 2) {
				if (j == lvl) i--, state++, state %= 4;
				else j--;
			}
			else if (state == 3) {
				if (i == lvl + 1) j++, lvl++, state++, state %= 4;
				else i--;
			}

			c++;
		}

		return ans;
	}
	vector<vector<int>> output = {
		{1,2,3,6,9,8,7,4,5},
		{1,2,3,4,8,12,11,10,9,5,6,7}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2,3},{4,5,6},{7,8,9}},
		{{1,2,3,4},{5,6,7,8},{9,10,11,12}}
	};
};