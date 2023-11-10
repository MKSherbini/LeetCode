#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

class RestoreTheArrayFromAdjacentPairs
{
public:
	// 278 ms, faster than 100% : 101.2 MB, less than 98.79%
	vector<int> solution(vector<vector<int>> adjacentPairs) {
		int n = size(adjacentPairs) + 1;
		unordered_map<int, vector<int>> adj(n);
		vector<int> ans(n);
		for (auto& p : adjacentPairs) {
			adj[p[0]].push_back(p[1]);
			adj[p[1]].push_back(p[0]);
		}
		int cur = -1;
		for (auto& [x, v] : adj) {
			if (size(v) == 1) {
				cur = x;
				break;
			}
		}
		Printer::print(adj);
		int i = 0;
		int last = -1;
		while (i < n) {
			Printer::print(i, cur, last);
			ans[i] = cur;
			cur = adj[cur][0] == last ? adj[cur][1] : adj[cur][0];
			last = ans[i];
			i++;
			if (size(adj[cur]) == 1) {
				ans[i++] = cur;
			}
		}

		return ans;
	}
	vector<vector<int>> output = {
		{1,2,3,4},
		{-2,4,1,-3},
		{100000,-100000}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{2,1},{3,4},{3,2}},
		{{4,-2},{1,4},{-3,1}},
		{{100000,-100000}}
	};
};