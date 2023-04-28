#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/similar-string-groups/


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

class SimilarStringGroups
{
public:
	// 190 ms, faster than 45.71% : 10.1 MB, less than 91.43%
	int solution(vector<string> strs) {
		int n = size(strs);
		UnionFind dsu(n);

		for (size_t i = 0; i < n; i++) {
			for (size_t j = i + 1; j < n; j++) {
				if (!dsu.sameSet(i, j) && valid(strs[i], strs[j])) dsu.unionSet(i, j);
			}
		}
		
		return dsu.numOfSets();
	}
	bool valid(string& s, string& s2) {
		int c = 0;
		for (size_t i = 0; i < size(s); i++) {
			if (s[i] != s2[i]) c++;
		}

		return c <= 2;
	}

	vector<int> output = {
		2,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"tars","rats","arts","star"},
		{"omv","ovm"}
	};
};