#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/as-far-from-land-as-possible/

class AsFarFromLandAsPossible
{
public:
	// 118 ms, faster than 30.39% : 35.6 MB, less than 13.26%
	int solution(vector<vector<int>> grid) {
		int n = size(grid);
		queue<pair<int, int>> land;

		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < n; j++) {
				if (grid[i][j] == 1)
					land.emplace(i, j);
			}
		}

		if (size(land) == n * n) return -1;

		int ans = -1;
		while (!empty(land)) {
			int c = size(land);
			ans++;

			while (c--) {
				auto& [i, j] = land.front();
				const vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
				for (auto& [dx, dy] : dir)
					if (valid(dx + i, n) && valid(dy + j, n) && grid[dx + i][dy + j] == 0)
						land.emplace(dx + i, dy + j), grid[dx + i][dy + j] = 1;
				land.pop();
			}
		}

		return ans;
	}
	bool valid(int x, int n) {
		return x >= 0 && x < n;
	}

	// 2770 ms, faster than 5.03% : 23.9 MB, less than 27.26%
	int solution2(vector<vector<int>> grid) {
		int n = size(grid);
		int ans = -1;

		vector<pair<int, int>> water, land;

		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < n; j++) {
				if (grid[i][j] == 0)
					water.emplace_back(i, j);
				else
					land.emplace_back(i, j);
			}
		}

		if (land.empty() || water.empty()) return -1;

		auto dis = [](const pair<int, int>& x, const pair<int, int>& y) {
			return abs(x.first - y.first) + abs(x.second - y.second); };

		for (auto& x : water) {
			int mn = INT_MAX;
			for (auto& y : land) {
				mn = min(mn, dis(x, y));
			}
			ans = max(ans, mn);
		}

		return ans;
	}
	vector<int> output = {
		2,
		4
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,0,1},{0,0,0},{1,0,1}},
		{{1,0,0},{0,0,0},{0,0,0}}
	};
};