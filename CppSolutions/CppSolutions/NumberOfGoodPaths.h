#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-good-paths/

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

class NumberOfGoodPaths
{
public:
	// 692 ms, faster than 93.4% : 225.8 MB, less than 30.51%
	int solution(vector<int> vals, vector<vector<int>> edges) {
		int n = size(vals);
		vector<vector<int>> mat(n);

		for (auto& e : edges)
			mat[e[0]].push_back(e[1]), mat[e[1]].push_back(e[0]);

		map<int, vector<int>> m;
		for (size_t i = 0; i < n; i++)
			m[vals[i]].push_back(i);

		UnionFind dsu(n);
		int ans = 0;

		for (auto& [val, nodes] : m) {
			for (auto node : nodes)
				for (auto adj : mat[node])
					if (vals[node] >= vals[adj])
						dsu.unionSet(node, adj);



			unordered_map<int, int > c;
			for (auto node : nodes)
				++c[dsu.findSet(node)];

			for (auto& [_, x] : c)
				ans += x * (x + 1) / 2;
		}

		return ans;
	}

	vector<int> output = {
		6,
		7,
		1
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,3,2,1,3},
		{1,1,2,2,3},
		{1}
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{0,2},{2,3},{2,4}},
		{{0,1},{1,2},{2,3},{2,4}},
		{}
	};
};