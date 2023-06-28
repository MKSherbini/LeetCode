#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/path-with-maximum-probability/

class PathWithMaximumProbability
{
public:
	// 527 ms, faster than 5.02% : 67.4 MB, less than 37.31%
	double solution(int n, vector<vector<int>> edges, vector<double> succProb, int start, int end) {
		vector<vector<pair<int, double>>> adj(n);
		for (size_t i = 0; i < size(edges); i++) {
			adj[edges[i][0]].push_back({ edges[i][1], succProb[i] });
			adj[edges[i][1]].push_back({ edges[i][0], succProb[i] });
		}

		const int OO = 1e9;
		vector<double> dist(n, 0);
		priority_queue<pair<int, int>> pq;
		pq.emplace(1, start);
		dist[start] = 1;

		while (!pq.empty()) {
			int i = pq.top().second;
			pq.pop();

			for (auto& [j, w] : adj[i]) {
				if (i != j && dist[j] < dist[i] * w) {
					dist[j] = dist[i] * w;
					pq.emplace(dist[j], j);
				}
			}
		}

		return dist[end];
	}
	vector<double> output = {
		0.25000,
		0.30000,
		0.00000
	};
	static constexpr int const& inputs = 5;
	vector<int> input1 = {
		3,
		3,
		3
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{1,2},{0,2}},
		{{0,1},{1,2},{0,2}},
		{{0,1}}
	};
	vector<vector<double>> input3 = {
		{0.5,0.5,0.2},
		{0.5,0.5,0.3},
		{0.5}
	};
	vector<int> input4 = {
		0,
		0,
		0
	};
	vector<int> input5 = {
		2,
		2,
		2
	};
};