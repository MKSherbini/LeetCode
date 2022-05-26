#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/pascals-triangle/

class PascalsTriangle
{
public:
	// 0 ms, faster than 100% : 6.3 MB, less than 91.1%
	vector<vector<int>> solution(int numRows) {
		vector<vector<int>> ans(numRows);
		for (size_t i = 0; i < numRows; i++)
			for (size_t j = 0; j < i + 1; j++)
				if (j == 0 || j == i)
					ans[i].push_back(1);
				else
					ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}},
		{{1}}
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		5,
		1
	};
};