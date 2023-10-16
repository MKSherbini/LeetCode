#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/pascals-triangle-ii/

class PascalsTriangleII
{
public:
	// 0 ms, faster than 100% : 6.6 MB, less than 51.35%
	vector<int> solution(int rowIndex) {
		vector ans(2, vector(rowIndex + 1, 0));
		int cur = 0, other = 1;
		for (size_t i = 0; i <= rowIndex; i++) {
			for (size_t j = 0; j < i + 1; j++) {
				if (j == 0 || j == i)
					ans[cur][j] = 1;
				else
					ans[cur][j] = ans[other][j - 1] + ans[other][j];
			}

			cur = other;
			other = 1 - cur;
		}

		return ans[other];
	}
	// 0 ms, faster than 100% : 6.9 MB, less than 17.31%
	vector<int> solution2(int rowIndex) {
		vector<vector<int>> ans(rowIndex + 1);
		for (size_t i = 0; i <= rowIndex; i++)
			for (size_t j = 0; j < i + 1; j++)
				if (j == 0 || j == i)
					ans[i].push_back(1);
				else
					ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);

		return ans[rowIndex];
	}
	vector<vector<int>> output = {
		{1,3,3,1},
		{1},
		{1,1}
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		3,
		0,
		1
	};
};