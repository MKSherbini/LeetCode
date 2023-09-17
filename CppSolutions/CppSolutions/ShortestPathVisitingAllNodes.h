#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/shortest-path-visiting-all-nodes/



class ShortestPathVisitingAllNodes
{
public:
	// 82 ms, faster than 46.13% : 17.2 MB, less than 51.19%
	int solution(vector<vector<int>> graph) {
		int n = size(graph);
		int allVis = (1 << n) - 1;

		auto cmp = [&](auto& x, auto& y) {
			return get<0>(x) != get<0>(y) ? get<0>(x) > get<0>(y) :get<2>(x).count() < get<2>(y).count(); };
		priority_queue<tuple<int, int, bitset<12>>, vector<tuple<int, int, bitset<12>>>, decltype(cmp)> pq(cmp);
		unordered_set<bitset<24>> visited;


		for (size_t i = 0; i < n; i++) {
			pq.push({ 0, i, 1 << i });
			bitset<24> b;
			b.set(i);
			b.set(i + 12);
			visited.insert(b);
		}

		while (!pq.empty()) {
			auto [cost, i, vis] = pq.top();
			pq.pop();
			Printer::print(pq);

			for (auto j : graph[i]) {
				auto newVis = vis;
				newVis.set(j);
				if (newVis == allVis) return cost + 1;

				bitset<24> b = newVis.to_ulong();
				b.set(j + 12);
				if (visited.count(b)) continue;
				visited.insert(b);

				pq.push({ cost + 1, j, newVis });
			}
		}

		return 0;
	}
	vector<int> output = {
		4,
		4
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2,3},{0},{0},{0}},
		{{1},{0,2,4},{1,3,4},{2},{1,2}}
	};
};