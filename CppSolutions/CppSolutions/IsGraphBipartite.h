#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/is-graph-bipartite/

class IsGraphBipartite
{
public:
	// 15 ms, faster than 99.2% : 13.3 MB, less than 94.95%
	bool solution(vector<vector<int>> graph) {
		int n = size(graph);
		vector<int> vis(n, -1);

		function<bool(int, bool)> f = [&](int i, bool c) -> bool {
			if (i == n) return true;
			if (vis[i] == c) return true;
			if (vis[i] == !c) return false;
			vis[i] = c;

			int ret = true;
			for (auto j : graph[i]) {
				ret &= f(j, !c);
				if (!ret) return ret;
			}

			return ret;
		};

		for (size_t i = 0; i < n; i++)
			if (vis[i] == -1 && !f(i, 0)) return false;

		return true;
	}

	vector<int> output = {
		false,
		true
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2,3},{0,2},{0,1,3},{0,2}},
		{{1,3},{0,2},{1,3},{0,2}}
	};
};