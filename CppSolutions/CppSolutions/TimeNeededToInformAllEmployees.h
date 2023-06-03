#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/time-needed-to-inform-all-employees/

class TimeNeededToInformAllEmployees
{
public:
	// 281 ms, faster than 88.65% : 122.2 MB, less than 45.49%
	int solution(int n, int headID, vector<int> manager, vector<int> informTime) {
		vector<vector<int>> adj(n);
		for (size_t i = 0; i < n; i++) {
			if (i == headID) continue;
			adj[manager[i]].push_back(i);
		}

		function<int(int)> f = [&](int i)-> int {
			if (empty(adj[i])) return 0;

			int ret = 0;
			for (auto j : adj[i])
				ret = max(ret, f(j));

			return informTime[i] + ret;
		};

		return f(headID);
	}
	vector<int> output = {
		0,
		1,
		3
	};
	static constexpr int const& inputs = 4;
	vector<int> input1 = {
		1,
		6,
		15
	};
	vector<int> input2 = {
		0,
		2,
		0
	};
	vector<vector<int>> input3 = {
		{-1},
		{2,2,-1,2,2,2},
		{-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6}
	};
	vector<vector<int>> input4 = {
		{0},
		{0,0,1,0,0,0},
		{1,1,1,1,1,1,1,0,0,0,0,0,0,0,0}
	};
};