#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/

class MinimumFuelCostToReportToTheCapital
{
public:
	// 556 ms, faster than 98.59% : 191.2 MB, less than 79.33%
	long long solution(vector<vector<int>> roads, int seats) {
		this->seats = seats;
		int n = size(roads) + 1;
		vector<vector<int>> adj(n);

		for (auto& r : roads)
			adj[r[0]].push_back(r[1]),
			adj[r[1]].push_back(r[0]);

		f(adj, 0, -1);

		return ans;
	}
	long long ans = 0, seats;
	int f(vector<vector<int>>& adj, int i, int p) {

		int c = 1;
		for (auto j : adj[i])
			if (p != j)
				c += f(adj, j, i);

		if (i)
			ans += max(1LL, (c + seats - 1) / seats);

		Printer::print(i, c, ans);
		return c;
	}

	vector<int> output = {
		3,
		7,
		0
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{0,1},{0,2},{0,3}},
		{{3,1},{3,2},{1,0},{0,4},{0,5},{4,6}},
		{}
	};
	vector<int> input2 = {
		5,
		2,
		1
	};
};