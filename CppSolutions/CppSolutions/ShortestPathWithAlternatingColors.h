#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/shortest-path-with-alternating-colors/

class ShortestPathWithAlternatingColors
{
public:
	// 11 ms, faster than 99.36% : 14.7 MB, less than 82.48%
	vector<int> solution(int n, vector<vector<int>> redEdges, vector<vector<int>> blueEdges) {
		vector<vector<pair<int, int>>> adj(n);
		vector<vector<int>> vis(n, vector(2, 0));

		for (auto& x : redEdges)
			adj[x[0]].emplace_back(x[1], 0);
		for (auto& x : blueEdges)
			adj[x[0]].emplace_back(x[1], 1);

		vector<int> ans(n, -1);
		queue<pair<int, int>> q;
		q.emplace(0, -1);
		int cnt = 0;
		while (!empty(q)) {
			int sz = size(q);
			Printer::print(cnt);
			while (sz--) {
				auto& [i, ci] = q.front();
				if (ans[i] == -1) ans[i] = cnt;
				Printer::print(i, ci);

				for (auto& [j, cj] : adj[i])
					if (ci != cj && !vis[j][cj])
						q.emplace(j, cj), vis[j][cj] = 1;
				q.pop();
			}
			cnt++;
		}

		return ans;
	}
	vector<vector<int>> output = {
		{0,1,-1},
		{0,1,-1}
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		3,
		3
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{1,2}},
		{{0,1}}
	};
	vector<vector<vector<int>>> input3 = {
		{},
		{{2,1}}
	};
};