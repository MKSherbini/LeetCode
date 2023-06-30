#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/last-day-where-you-can-still-cross/


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

class LastDayWhereYouCanStillCross
{
public:
	// 369 ms, faster than 79.24% : 115.2 MB, less than 65.25%
	int solution(int row, int col, vector<vector<int>> cells) {
		unordered_set<int> water;
		int n = row * col;
		UnionFind dsu(n + 2);
		int l = n;
		int r = n + 1;
		int ans = 0;
		for (auto& cell : cells) {
			cell[0]--, cell[1]--;
			int g = col * cell[0] + cell[1];
			water.insert(g);
			const vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
			for (auto [dx, dy] : dir) {
				if (!valid(dx + cell[0], row) || !valid(dy + cell[1], col)) continue;
				int g2 = col * (dx + cell[0]) + (dy + cell[1]);
				if (water.count(g2))
					dsu.unionSet(g, g2);
			}
			if (cell[1] == 0) dsu.unionSet(l, g);
			if (cell[1] == col - 1) dsu.unionSet(r, g);
			if (dsu.sameSet(r, l)) break;
			ans++;
		}

		for (size_t i = 0; i < n + 2; i++) {
			if (dsu.sameSet(i, r)) Printer::print(i);
		}

		return ans;
	}
	bool valid(int x, int n) {
		return x >= 0 && x < n;
	}
	vector<int> output = {
		2,
		1,
		3,
		3
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		2,
		2,
		3,
		6
	};
	vector<int> input2 = {
		2,
		2,
		3,
		2
	};
	vector<vector<vector<int>>> input3 = {
		{{1,1},{2,1},{1,2},{2,2}},
		{{1,1},{1,2},{2,1},{2,2}},
		{{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}},
		{{4,2},{6,2},{2,1},{4,1},{6,1},{3,1},{2,2},{3,2},{1,1},{5,1},{5,2},{1,2}}
	};
};