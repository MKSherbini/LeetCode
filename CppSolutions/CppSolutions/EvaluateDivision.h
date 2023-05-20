#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/evaluate-division/

class EvaluateDivision
{
public:
	// 0 ms, faster than 100% : 8.1 MB, less than 90.73%
	vector<double> solution(vector<vector<string>> equations, vector<double> values, vector<vector<string>> queries) {
		unordered_map<string, int> m;
		int c = 0;
		vector<vector<pair<int, double>>> adj;

		for (size_t i = 0; i < size(equations); i++) {
			auto& e = equations[i];
			if (!m.count(e[0])) m[e[0]] = c++, adj.push_back({});
			if (!m.count(e[1])) m[e[1]] = c++, adj.push_back({});

			adj[m[e[0]]].emplace_back(m[e[1]], values[i]);
			adj[m[e[1]]].emplace_back(m[e[0]], 1 / values[i]);
		}

		function<double(int, int)> f = [&](int a, int b)->double {
			queue<pair<int, double>> q;
			bitset<40> vis;
			q.emplace(a, 1);

			while (!q.empty()) {
				auto [i, cost] = q.front();
				q.pop();
				vis.set(i);
				for (auto& [j, cost2] : adj[i]) {
					if (j == b) return cost * cost2;

					if (!vis.test(j)) {
						q.emplace(j, cost * cost2);
					}
				}
			}
			return -1;
		};

		vector<double> ans(size(queries));
		for (size_t i = 0; i < size(queries); i++) {
			auto& q = queries[i];
			ans[i] = m.count(q[0]) && m.count(q[1]) ? f(m[q[0]], m[q[1]]) : -1;
		}

		return ans;
	}
	vector<vector<double>> output = {
		{6.00000,0.50000,-1.00000,1.00000,-1.00000},
		{3.75000,0.40000,5.00000,0.20000},
		{0.50000,2.00000,-1.00000,-1.00000}
	};
	static constexpr int const& inputs = 3;
	vector<vector<vector<string>>> input1 = {
		{{"a","b"},{"b","c"}},
		{{"a","b"},{"b","c"},{"bc","cd"}},
		{{"a","b"}}
	};
	vector<vector<double>> input2 = {
		{2.0,3.0},
		{1.5,2.5,5.0},
		{0.5}
	};
	vector<vector<vector<string>>> input3 = {
		{{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}},
		{{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}},
		{{"a","b"},{"b","a"},{"a","c"},{"x","y"}}
	};
};