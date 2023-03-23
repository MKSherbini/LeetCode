#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-operations-to-make-network-connected/

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
class NumberOfOperationsToMakeNetworkConnected
{
public:
	// 102 ms, faster than 97.32% : 38.1 MB, less than 87.79%
	int solution(int n, vector<vector<int>> connections) {
		UnionFind dsu(n);
		int allowed = 0;
		for (auto& c : connections) {
			if (dsu.sameSet(c[0], c[1]))
				allowed++;
			else
				dsu.unionSet(c[0], c[1]);
		}
		Printer::print(dsu.numOfSets(), allowed);

		return allowed < dsu.numOfSets() - 1 ? -1 : dsu.numOfSets() - 1;
	}
	vector<int> output = {
		1,
		2,
		-1
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		4,
		6,
		6
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{0,2},{1,2}},
		{{0,1},{0,2},{0,3},{1,2},{1,3}},
		{{0,1},{0,2},{0,3},{1,2}}
	};
};