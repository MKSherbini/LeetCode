#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-all-people-with-secret/

class UnionFind {
private:
	vector<int> p, ranks;
public:
	UnionFind(int N) {
		p.assign(N, 0), ranks.assign(N, 0);
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
			int x = findSet(i), y = findSet(j);
			if (ranks[x] > ranks[y]) {
				p[y] = x;
			}
			else {
				p[x] = y;
				if (ranks[x] == ranks[y])
					ranks[y]++;
			}
		}
	}

	void reset(int i) {
		p[i] = i, ranks[i] = 0;
	}
};
class FindAllPeopleWithSecret
{
public:
	// 337 ms, faster than 99.18% : 135.9 MB, less than 96.72%
	vector<int> solution(int n, vector<vector<int>> meetings, int firstPerson) {
		sort(begin(meetings), end(meetings),
			[](const auto& x, const auto& y) {return x[2] < y[2]; });

		UnionFind dsu(n);
		dsu.unionSet(0, firstPerson);
		for (size_t i = 0; i < size(meetings); i++) {
			size_t j = i;
			for (; j < size(meetings); j++) {
				if (meetings[j][2] != meetings[i][2]) break;
				dsu.unionSet(meetings[j][0], meetings[j][1]);
			}
			for (j = i; j < size(meetings); j++) {
				if (meetings[j][2] != meetings[i][2]) break;
				if (!dsu.sameSet(meetings[j][0], 0))
					dsu.reset(meetings[j][0]), dsu.reset(meetings[j][1]);
			}

			i = j - 1;
		}

		vector<int> ans;
		for (size_t i = 0; i < n; i++) {
			if (dsu.sameSet(i, 0)) ans.push_back(i);
		}

		return ans;
	}
	vector<vector<int>> output = {
		{0,1,2,3,5},
		{0,1,3},
		{0,1,2,3,4}
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		6,
		4,
		5
	};
	vector<vector<vector<int>>> input2 = {
		{{1,2,5},{2,3,8},{1,5,10}},
		{{3,1,3},{1,2,2},{0,3,3}},
		{{3,4,2},{1,2,1},{2,3,1}}
	};
	vector<int> input3 = {
		1,
		3,
		1
	};
};