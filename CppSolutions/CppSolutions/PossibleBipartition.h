#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/possible-bipartition/

class PossibleBipartition
{
public:
	// 192 ms, faster than 98.64% : 64.7 MB, less than 70.62%
	bool solution(int n, vector<vector<int>> dislikes) {
		vector<vector<int>> mat(n);
		vector<int> vis(n, -1);

		for (auto& p : dislikes)
			mat[p[0] - 1].push_back(p[1] - 1), mat[p[1] - 1].push_back(p[0] - 1);

		for (size_t i = 0; i < n; i++)
			if (vis[i] == -1 && !f(mat, vis, i, 0)) return false;

		return true;
	}
	bool f(vector<vector<int>>& mat, vector<int>& vis, int i, int c) {
		if (vis[i] != -1) return vis[i] == c;

		vis[i] = c;
		int ret = true;
		for (auto j : mat[i])
			ret &= f(mat, vis, j, 1 - c);

		return ret;
	}


	vector<int> output = {
		true,
		false,
		false
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		4,
		3,
		5
	};
	vector<vector<vector<int>>> input2 = {
		{{1,2},{1,3},{2,4}},
		{{1,2},{1,3},{2,3}},
		{{1,2},{2,3},{3,4},{4,5},{1,5}}
	};
};