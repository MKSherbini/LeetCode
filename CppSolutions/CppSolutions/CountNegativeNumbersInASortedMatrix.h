#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class CountNegativeNumbersInASortedMatrix
{
public:
	// 9 ms, faster than 98.31% : 10.3 MB, less than 99.08%
	int solution(vector<vector<int>> grid) {
		int ans = 0;
		for (int i = size(grid) - 1; i >= 0; i--) {
			if (grid[i].back() >= 0) break;
			for (int j = size(grid[0]) - 1; j >= 0; j--) {
				if (grid[i][j] >= 0) break;
				ans++;
			}
		}
		return ans;
	}
	vector<int> output = {
		8,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}},
		{{3,2},{1,0}}
	};
};