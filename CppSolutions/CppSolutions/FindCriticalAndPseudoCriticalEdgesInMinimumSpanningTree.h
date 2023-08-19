#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/

class UnionFind {
private:
	vector<int> p;
	int numsets;
public:
	UnionFind(int N) {
		p.assign(N, 0), numsets = N;

		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}

	bool sameSet(int i, int j) {
		return (findSet(i) == findSet(j));
	}

	void unionSet(int i, int j) {
		if (!sameSet(i, j)) {
			numsets--;
			int x = findSet(i), y = findSet(j);
			p[x] = y;
		}
	}

	int numOfSets() {
		return numsets;
	}
};

class FindCriticalAndPseudoCriticalEdgesInMinimumSpanningTree
{
public:
	// 113 ms, faster than 81.84% : 14.6 MB, less than 89.74%
	vector<vector<int>> solution(int n, vector<vector<int>> edges) {
		int m = size(edges);
		for (size_t i = 0; i < m; i++) {
			edges[i].push_back(i);
		}

		sort(begin(edges), end(edges), [](auto& a, auto& b) { return a[2] < b[2]; });

		auto calcW = [&](UnionFind& dsu, int excluded) {
			int w = 0;
			for (size_t i = 0; i < m; i++) {
				if (i != excluded && !dsu.sameSet(edges[i][0], edges[i][1])) {
					dsu.unionSet(edges[i][0], edges[i][1]);
					w += edges[i][2];
				}
			}
			return w;
		};

		UnionFind dsu(n);
		int w = calcW(dsu, -1);

		vector<vector<int>> ans(2);
		for (size_t i = 0; i < m; i++) {
			UnionFind dsuExclude(n);
			int wExclude = calcW(dsuExclude, i);

			if (dsuExclude.numOfSets() != 1 || wExclude > w) {
				ans[0].push_back(edges[i][3]);
			}
			else {
				UnionFind dsuInclude(n);
				dsuInclude.unionSet(edges[i][0], edges[i][1]);
				int wInclude = edges[i][2] + calcW(dsuInclude, i);

				if (wInclude == w) {
					ans[1].push_back(edges[i][3]);
				}
			}
		}
		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{0,1},{2,3,4,5}},
		{{},{0,1,2,3}}
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		5,
		4
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}},
		{{0,1,1},{1,2,1},{2,3,1},{0,3,1}}
	};
};