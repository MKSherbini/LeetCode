#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

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

class RemoveMaxNumberOfEdgesToKeepGraphFullyTraversable
{
public:
	// 523 ms, faster than 84.78% : 139.8 MB, less than 65.58%
	int solution(int n, vector<vector<int>> edges) {
		UnionFind dsu1(n);
		UnionFind dsu2(n);
		int ans = 0;
		for (auto& e : edges) {
			if (e[0] == 3) {
				if (dsu1.sameSet(e[1] - 1, e[2] - 1) && dsu2.sameSet(e[1] - 1, e[2] - 1)) ans++;
				else  dsu1.unionSet(e[1] - 1, e[2] - 1), dsu2.unionSet(e[1] - 1, e[2] - 1);
			}
		}
		for (auto& e : edges) {
			if (e[0] == 1) {
				if (dsu1.sameSet(e[1] - 1, e[2] - 1)) ans++;
				else dsu1.unionSet(e[1] - 1, e[2] - 1);
			}
			else if (e[0] == 2) {
				if (dsu2.sameSet(e[1] - 1, e[2] - 1)) ans++;
				else dsu2.unionSet(e[1] - 1, e[2] - 1);
			}
		}
		if (dsu1.numOfSets() > 1 || dsu2.numOfSets() > 1)
			return -1;
		return ans;
	}
	vector<int> output = {
		2,
		0,
		-1
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		4,
		4,
		4
	};
	vector<vector<vector<int>>> input2 = {
		{{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}},
		{{3,1,2},{3,2,3},{1,1,4},{2,1,4}},
		{{3,2,3},{1,1,2},{2,3,4}}
	};
};