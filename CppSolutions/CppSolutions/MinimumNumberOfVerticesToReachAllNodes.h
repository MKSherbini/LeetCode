#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class MinimumNumberOfVerticesToReachAllNodes
{
public:
	// 302 ms, faster than 68.58% : 93.4 MB, less than 99.9%
	vector<int> solution(int n, vector<vector<int>> edges) {
		vector<bool> vis(n);
		for (auto& e : edges)
			vis[e[1]] = 1;

		vector<int> ans;
		for (size_t i = 0; i < n; i++)
			if (!vis[i])
				ans.push_back(i);

		return ans;
	}
	vector<vector<int>> output = {
		{0,3},
		{0,2,3}
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		6,
		5
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{0,2},{2,5},{3,4},{4,2}},
		{{0,1},{2,1},{3,1},{1,4},{2,4}}
	};
};