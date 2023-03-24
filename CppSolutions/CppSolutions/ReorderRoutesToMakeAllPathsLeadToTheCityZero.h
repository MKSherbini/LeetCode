#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class ReorderRoutesToMakeAllPathsLeadToTheCityZero
{
public:
	// 331 ms, faster than 97.51% : 101.2 MB, less than 90.48%
	int solution(int n, vector<vector<int>> connections) {
		vector<vector<pair<int, int>>> v(n);

		for (auto& c : connections)
			v[c[0]].emplace_back(c[1], -1),
			v[c[1]].emplace_back(c[0], 1);

		//Printer::print(v);
		queue<pair<int, int>> q;
		q.emplace(-1, 0);
		int ans = 0;
		while (!q.empty()) {
			auto [p, i] = q.front();
			q.pop();

			for (auto& [j, dir] : v[i]) {
				if (p == j) continue;
				q.emplace(i, j);
				if (dir == -1)
					ans++;
			}
		}
		return ans;
	}
	vector<int> output = {
		3,
		2,
		0
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		6,
		5,
		3
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{1,3},{2,3},{4,0},{4,5}},
		{{1,0},{1,2},{3,2},{3,4}},
		{{1,0},{2,0}}
	};
};