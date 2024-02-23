#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/cheapest-flights-within-k-stops/

class CheapestFlightsWithinKStops
{
public:
	// 12 ms, faster than 90.03% : 15.6 MB, less than 67.51%
	int solution(int n, vector<vector<int>> flights, int src, int dst, int k) {
		const int OO = 1e6;
		vector visCost(2, vector(n, OO));
		int cur = 0, other = 1;
		visCost[other][src] = 0;
		for (size_t i = 0; i <= k; i++) {
			Printer::print(visCost);
			for (auto& f : flights) {
				if (visCost[other][f[0]] != OO) {
					visCost[cur][f[1]] = min(visCost[cur][f[1]], visCost[other][f[0]] + f[2]);
				}
			}
			for (size_t j = 0; j < n; j++) {
				visCost[cur][j] = min(visCost[cur][j], visCost[other][j]);
			}
			cur = other;
			other = 1 - cur;
		}

		return visCost[other][dst] == OO ? -1 : visCost[other][dst];
	}

	// 19 ms, faster than 94.79% : 13.1 MB, less than 75.69%
	int solution2(int n, vector<vector<int>> flights, int src, int dst, int k) {
		vector<vector<int>> adj(n);

		for (size_t i = 0; i < size(flights); i++)
			adj[flights[i][0]].push_back(i);

		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
		q.push({ 0, src, k + 1 });
		vector<int> visCost(n, OO);
		vector<int> visStep(n, k + 1);
		int ans = OO;
		while (!q.empty()) {
			auto [cost, i, step] = q.top();
			Printer::print(q.top());
			Printer::print(q);
			q.pop();

			if (i == dst)
				return cost;

			if (step == 0)
				continue;

			visStep[i] = step--;
			visCost[i] = cost;

			for (auto j : adj[i]) {
				if (visStep[flights[j][1]] < step || visCost[flights[j][1]] > cost + flights[j][2])
					q.push({ cost + flights[j][2], flights[j][1] , step });
			}
		}

		return -1;
	}

	const int OO = 1e6;
	vector<int> output = {
		700,
		200,
		500
	};
	static constexpr int const& inputs = 5;
	vector<int> input1 = {
		4,
		3,
		3
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}},
		{{0,1,100},{1,2,100},{0,2,500}},
		{{0,1,100},{1,2,100},{0,2,500}}
	};
	vector<int> input3 = {
		0,
		0,
		0
	};
	vector<int> input4 = {
		3,
		2,
		2
	};
	vector<int> input5 = {
		1,
		1,
		0
	};
};