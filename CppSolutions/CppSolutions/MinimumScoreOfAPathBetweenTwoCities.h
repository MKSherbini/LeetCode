#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

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
class MinimumScoreOfAPathBetweenTwoCities
{
public:
	// 531 ms, faster than 53.7% : 102.9 MB, less than 94%
	int solution(int n, vector<vector<int>> roads) {
		UnionFind dsu(n + 1);

		sort(begin(roads), end(roads), [](const auto& x, const auto& y) {return x[2] < y[2]; });

		for (auto& r : roads) {
			dsu.unionSet(r[0], r[1]);
		}

		Printer::print(roads);
		int ans = INT_MAX;
		for (auto& r : roads) {
			if (dsu.sameSet(r[0], n) || dsu.sameSet(r[1], n)) return r[2];
		}

		return -1;
	}
	vector<int> output = {
		5,
		2
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		4,
		4
	};
	vector<vector<vector<int>>> input2 = {
		{{1,2,9},{2,3,6},{2,4,5},{1,4,7}},
		{{1,2,2},{1,3,4},{3,4,7}}
	};
};