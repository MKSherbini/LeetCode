#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/cherry-pickup-ii/?envType=daily-question&envId=2024-02-11

class CherryPickupII
{
public:
	// 127 ms, faster than 28.55% : 20.4 MB, less than 6.58%
	int solution(vector<vector<int>> grid) {
		int n = size(grid), m = size(grid[0]);
		function<bool(int, int)> valid = [&](int x, int n) -> bool {
			return x >= 0 && x < n;
		};
		vector mem(n, vector(m, vector(m, -1)));
		function<int(int, int, int)> f = [&](int i, int j1, int j2) -> int {
			if (i == n || !valid(j1, m) || !valid(j2, m) || j1 == j2) return 0;

			if (mem[i][j1][j2] != -1) return mem[i][j1][j2];

			int ret = 0;
			for (int d1 = -1; d1 <= 1; d1++) {
				for (int d2 = -1; d2 <= 1; d2++) {
					ret = max(ret, f(i + 1, j1 + d1, j2 + d2));
				}
			}

			return mem[i][j1][j2] = ret + grid[i][j1] + grid[i][j2];
		};

		return f(0, 0, m - 1);
	}
	vector<int> output = {
		24,
		28
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{3,1,1},{2,5,1},{1,5,5},{2,1,1}},
		{{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}}
	};
};