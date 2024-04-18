#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/island-perimeter/

class IslandPerimeter
{
public:
	// 85 ms, faster than 26.25% : 109.5 MB, less than 6.1%
	int solution(vector<vector<int>> grid) {
		int n = size(grid), m = size(grid[0]);
		int ans = 0;
		function<bool(int, int)> valid = [&](int x, int n) -> bool {
			return x >= 0 && x < n;
			};
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				if (grid[i][j]) {
					const vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
					for (auto [dx, dy] : dir) {
						if (!valid(i + dx, n) || !valid(j + dy, m) || !grid[i + dx][j + dy]) ans++;
					}
				}
			}
		}

		return ans;
	}
	vector<int> output = {
		16,
		4,
		4
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}},
		{{1}},
		{{1,0}}
	};
};