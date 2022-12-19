#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-if-path-exists-in-graph/

class FindIfPathExistsInGraph
{
public:
	// 722 ms, faster than 85.17% : 213.8 MB, less than 24.69%
	bool solution(int n, vector<vector<int>> edges, int source, int destination) {
		vector<int> vis(n, 0);
		vector<vector<int>> mat(n);
		for (auto& e : edges)
			mat[e[0]].push_back(e[1]), mat[e[1]].push_back(e[0]);
		return f(source, mat, vis, destination);
	}
	bool f(int i, vector<vector<int>>& edges, vector<int>& vis, int dest) {
		if (vis[i]) return false;
		if (i == dest) return true;

		vis[i] = 1;
		int ret = false;
		for (auto x : edges[i]) {
			ret |= f(x, edges, vis, dest);
		}
		return ret;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 4;
	vector<int> input1 = {
		3,
		6
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{1,2},{2,0}},
		{{0,1},{0,2},{3,5},{5,4},{4,3}}
	};
	vector<int> input3 = {
		0,
		0
	};
	vector<int> input4 = {
		2,
		5
	};
};