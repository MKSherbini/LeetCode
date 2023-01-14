#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
class UnionFind {
private:
	int numsets;
public:
	vector<int> p;
	UnionFind(int n) {
		p.resize(n), numsets = n;
		for (int i = 0; i < n; i++)
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
			p[x] = y;
		}
	}

	int numOfSets() {
		return numsets;
	}
};
class LexicographicallySmallestEquivalentString
{
public:
	// 0 ms, faster than 100% : 6.4 MB, less than 94.5%
	string solution(string s1, string s2, string baseStr) {
		UnionFind u(26);
		for (size_t i = 0; i < size(s1); i++)
			u.unionSet(s1[i] - 'a', s2[i] - 'a');

		for (char c = 0; c < 26; c++)
			u.findSet(c);
		vector<char> best(26, -1);

		for (size_t i = 0; i < size(u.p); i++)
			for (size_t j = i; j < size(u.p); j++)
				if (u.p[i] == u.p[j] && best[j] == -1)
					best[j] = 'a' + i;

		for (auto& c : baseStr)
			c = best[c - 'a'];

		return baseStr;
	}
	vector<string> output = {
		"makkek",
		"hdld",
		"aauaaaaada"
	};
	static constexpr int const& inputs = 3;
	vector<string> input1 = {
		"parker",
		"hello",
		"leetcode"
	};
	vector<string> input2 = {
		"morris",
		"world",
		"programs"
	};
	vector<string> input3 = {
		"parser",
		"hold",
		"sourcecode"
	};
};