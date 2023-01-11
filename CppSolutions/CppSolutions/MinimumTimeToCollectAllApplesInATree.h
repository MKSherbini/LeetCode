#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

class MinimumTimeToCollectAllApplesInATree
{
public:
	// 165 ms, faster than 98.99% : 60.3 MB, less than 93.96%
	int solution(int n, vector<vector<int>> edges, vector<bool> hasApple) {
		vector<vector<int>> mat(n);
		for (auto& e : edges)
			mat[e[0]].push_back(e[1]), mat[e[1]].push_back(e[0]);

		return max((f(mat, hasApple, 0, -1) - 1) * 2, 0);
	}
	int f(vector<vector<int>>& mat, vector<bool>& hasApple, int i, int p) {

		int ret = 0;
		for (auto j : mat[i])
			if (p != j)
				ret += f(mat, hasApple, j, i);

		return ret || hasApple[i] ? ret + 1 : 0;
	}
	vector<int> output = {
		8,
		6,
		0
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		7,
		7,
		7
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}},
		{{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}},
		{{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}}
	};
	vector<vector<bool>> input3 = {
		{false,false,true,false,true,true,false},
		{false,false,true,false,false,true,false},
		{false,false,false,false,false,false,false}
	};
};