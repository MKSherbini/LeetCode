#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-all-groups-of-farmland/

class FindAllGroupsOfFarmland {
public:
	// 991 ms, faster than 5.09% : 115.7 MB, less than 25.09%
	// should prolly traverse recursively corner to corner but too laazy
	vector<vector<int>> solution(vector<vector<int>> land) {
		int n = size(land), m = size(land[0]);
		function<bool(int, int)> valid = [&](int x, int n) -> bool {
			return x >= 0 && x < n;
			};
		int lastI = 0, lastJ = 0;
		function<void(int, int)> sink = [&](int i, int j) -> void {
			if (!valid(i, n) || !valid(j, m) || !land[i][j]) return;
			land[i][j] = 0;
			lastI = max(lastI, i);
			lastJ = max(lastJ, j);
			const vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
			for (auto [dx, dy] : dir) {
				sink(i + dx, j + dy);
			}
			};

		vector<vector<int>> ans;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (land[i][j]) {
					lastI = 0, lastJ = 0;
					sink(i, j);
					ans.push_back({ i, j, lastI, lastJ });
				}
			}
		}

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{0,0,0,0},{1,1,2,2}},
		{{0,0,1,1}},
		{}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,0,0},{0,1,1},{0,1,1}},
		{{1,1},{1,1}},
		{{0}}
	};
};