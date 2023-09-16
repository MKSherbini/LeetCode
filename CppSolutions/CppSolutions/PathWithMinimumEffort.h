#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/path-with-minimum-effort/?envType=daily-question&envId=2023-09-16

class PathWithMinimumEffort
{
public:
	// 158 ms, faster than 40.92% : 30.9 MB, less than 29.19%
	int solution(vector<vector<int>> heights) {
		int n = size(heights), m = size(heights[0]);
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

		function<bool(int, int)> valid = [&](int x, int n) -> bool {
			return x >= 0 && x < n;
		};
		pq.push({ 0, 0, 0 });
		vector mnEffort(n, vector(m, INT_MAX));

		while (true) {
			auto [effort, i, j] = pq.top();
			pq.pop();
			if (i == n - 1 && j == m - 1) {
				Printer::print(mnEffort);
				return effort;
			}

			const vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
			for (auto& [dx, dy] : dir) {
				auto ii = i + dx, jj = j + dy;
				if (!valid(ii, n) || !valid(jj, m)) continue;
				auto newEffort = max(effort, abs(heights[ii][jj] - heights[i][j]));
				if (mnEffort[ii][jj] <= newEffort) continue;

				mnEffort[ii][jj] = newEffort;
				pq.push({ newEffort, ii, jj });
			}
		}

		return 0;
	}
	vector<int> output = {
		2,
		1,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2,2},{3,8,2},{5,3,5}},
		{{1,2,3},{3,8,4},{5,3,5}},
		{{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}}
	};
};