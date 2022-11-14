#pragma once
#include "stdc++.h"

using namespace std;

//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class UnionFind {
private:
	int numsets;
public:
	unordered_map<int, int> p;
	UnionFind() {
		numsets = 0;
	}

	int findSet(int i) {
		if (p.find(i) == end(p)) p[i] = i, ++numsets;
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

class MostStonesRemovedWithSameRowOrColumn
{
public:
	// 44 ms, faster than 98.82% : 16.3 MB, less than 60.07%
	int solution(vector<vector<int>> stones) {
		UnionFind u;

		for (auto& s : stones)
			u.unionSet(s[0] + 10001, s[1]);

		Printer::print(u.p);
		return size(stones) - u.numOfSets();
	}
	vector<int> output = {
		5,
		3,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}},
		{{0,0},{0,2},{1,1},{2,0},{2,2}},
		{{0,0}}
	};
};

