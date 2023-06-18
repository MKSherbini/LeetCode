#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

class NumberOfIncreasingPathsInAGrid
{
public:
	// 672 ms, faster than 14.98% : 93.5 MB, less than 14.84%
	int solution(vector<vector<int>> grid) {
		int n = size(grid), m = size(grid[0]);
		const int MOD = 1e9 + 7;

		vector mem(n, vector<int>(m, -1));
		function<int(int, int)> valid = [&](int x, int n)->int {
			return x >= 0 && x < n;
		};
		function<int(int, int)> f = [&](int i, int j)->int {
			if (mem[i][j] != -1) return mem[i][j];

			long long ret = 1;
			const vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
			for (auto& [dx, dy] : dir)
				if (valid(i + dx, n) && valid(j + dy, m) && grid[i + dx][j + dy] < grid[i][j])
					ret += f(i + dx, j + dy), ret %= MOD;

			return mem[i][j] = ret;
		};

		long long ans = 0;
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				ans += f(i, j), ans %= MOD;
			}
		}

		return ans;
	}
	vector<int> output = {
		8,
		3
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,1},{3,4}},
		{{1},{2}}
	};
};