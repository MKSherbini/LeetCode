#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class UnionFind {
private:
	vector<int> p, ranks, setsize;
	int numsets;
	int maxSize = 0;
public:
	UnionFind(int N) {
		p.assign(N, 0), setsize.assign(N, 1), numsets = N, ranks.assign(N, 0);

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
			if (ranks[x] > ranks[y]) {
				p[y] = x;
				setsize[x] += setsize[y];
			}
			else {
				p[x] = y;
				setsize[y] += setsize[x];
				if (ranks[x] == ranks[y])
					ranks[y]++;
			}
		}
	}

	int numOfSets() {
		return numsets;
	}

	int sizeOfSet(int i) {
		return setsize[findSet(i)];
	}
};

class CountUnreachablePairsOfNodesInAnUndirectedGraph
{
public:
	// 448 ms, faster than 98.63% : 147.6 MB, less than 92.38%
	long long solution(int n, vector<vector<int>> edges) {
		UnionFind dsu(n);
		for (auto& e : edges)
			dsu.unionSet(e[0], e[1]);

		unordered_set<int> s;
		for (size_t i = 0; i < n; i++)
			s.insert(dsu.findSet(i));

		long long rem = n, ans = 0;
		for (auto i : s) {
			rem -= dsu.sizeOfSet(i);
			ans += rem * dsu.sizeOfSet(i);
		}

		return ans;
	}
	vector<int> output = {
		0,
		14
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		3,
		7
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{0,2},{1,2}},
		{{0,2},{0,5},{2,4},{1,6},{5,4}}
	};
};