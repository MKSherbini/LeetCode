#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/satisfiability-of-equality-equations/

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

class SatisfiabilityOfEqualityEquations
{
public:
	// 3 ms, faster than 96.94% : 11.3 MB, less than 88.77%
	bool solution(vector<string> equations) {
		UnionFind u(26);

		for (auto s : equations) {
			if (s[1] == '=') u.unionSet(s[0] - 'a', s[3] - 'a');
		}
		for (auto s : equations) {
			if (s[1] == '!'&&u.sameSet(s[0] - 'a', s[3] - 'a')) return 0;
		}

		return 1;
	}
	vector<int> output = {
		false,
		true
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"a==b","b!=a"},
		{"b==a","a==b"}
	};
};