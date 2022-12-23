#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sum-of-distances-in-tree/

class SumOfDistancesInTree
{
public:
	// 275 ms, faster than 93.24% : 87.2 MB, less than 80.42%
	vector<int> solution(int n, vector<vector<int>> edges) {
		this->n = n;
		mat.resize(n);
		cnts.assign(n, 1), lens.resize(n);

		for (auto& p : edges)
			mat[p[0]].push_back(p[1]), mat[p[1]].push_back(p[0]);

		f(0, -1);
		ff(0, -1);
		return lens;
	}
	void f(int i, int p) {
		for (auto j : mat[i])
			if (j != p) {
				f(j, i);
				cnts[i] += cnts[j];
				lens[i] += lens[j] + cnts[j];
			}
	}
	void ff(int i, int p) {
		for (auto j : mat[i])
			if (j != p) {
				lens[j] = lens[i] - cnts[j] + n - cnts[j];
				ff(j, i);
			}
	}

	vector<int> cnts, lens;
	vector<vector<int>> mat;
	int n;

	vector<vector<int>> output = {
		{8,12,6,10,10,10},
		{0},
		{1,1}
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		6,
		1,
		2
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{0,2},{2,3},{2,4},{2,5}},
		{},
		{{1,0}}
	};
};