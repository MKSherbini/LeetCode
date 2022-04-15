#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/unique-paths/

class UniquePaths
{
public:
	// 0 ms, faster than 100% : 6.4 MB, less than 51.56%
	int solution(int m, int n) {
		vector<vector<int>> mem(m, vector<int>(n, -1));
		return curse(mem, m - 1, n - 1);
	}
	int curse(vector<vector<int>>& mem, int i, int j) {
		if (i < 0 || j < 0) return 0;
		if (i == 0 && j == 0) return 1;
		if (mem[i][j] != -1) return mem[i][j];

		return mem[i][j] = curse(mem, i - 1, j) + curse(mem, i, j - 1);
	}
	vector<int> output = {
		28,
		3
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		3,
		3
	};
	vector<int> input2 = {
		7,
		2
	};
};