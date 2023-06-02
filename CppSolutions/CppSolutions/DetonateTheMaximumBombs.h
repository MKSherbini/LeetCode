#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/detonate-the-maximum-bombs/

class DetonateTheMaximumBombs
{
public:
	// 283 ms, faster than 38.01% : 14.4 MB, less than 87.79%
	int solution(vector<vector<int>> bombs) {
		int n = size(bombs);
		vector<vector<int>> adj(n);
		for (size_t i = 0; i < n; i++) {
			for (size_t j = i + 1; j < n; j++) {
				if (pow(bombs[i][0] - bombs[j][0], 2)
					+ pow(bombs[i][1] - bombs[j][1], 2)
					<= pow(bombs[i][2], 2)) {
					adj[i].push_back(j);
				}
				if (pow(bombs[i][0] - bombs[j][0], 2)
					+ pow(bombs[i][1] - bombs[j][1], 2)
					<= pow(bombs[j][2], 2)) {
					adj[j].push_back(i);
				}
			}
		}

		vector<bool> vis(n, 0);
		function<int(int)> f = [&](int i)-> int {
			if (vis[i]) return 0;

			vis[i] = 1;
			int ret = 1;
			for (auto j : adj[i])
				ret += f(j);

			return ret;
		};

		int ans = 0;
		for (size_t i = 0; i < n; i++) {
			ans = max(ans, f(i));
			fill(begin(vis), end(vis), 0);
		}

		return ans;
	}
	vector<int> output = {
		2,
		1,
		5
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{2,1,3},{6,1,4}},
		{{1,1,5},{10,10,5}},
		{{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}}
	};
};