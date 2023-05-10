#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/spiral-matrix-ii/

class SpiralMatrixII
{
public:
	// 0 ms, faster than 100% : 6.4 MB, less than 90.43%
	vector<vector<int>> solution(int n) {
		int i = 0, j = 0;
		int state = 0;

		vector<vector<int>> ans(n, vector<int>(n));
		int c = 1;
		int lvl = 0;
		while (c <= n * n) {
			ans[i][j] = c;

			if (state == 0) {
				if (j == n - lvl - 1) i++, state++, state %= 4;
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
	vector<vector<vector<int>>> output = {
		{{1,2,3},{8,9,4},{7,6,5}},
		{{1}}
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		3,
		1
	};
};