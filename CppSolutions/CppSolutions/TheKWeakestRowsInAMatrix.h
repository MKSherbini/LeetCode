#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class TheKWeakestRowsInAMatrix
{
public:
	// 6 ms, faster than 91.97% : 10.8 MB, less than 9.15%
	vector<int> solution(vector<vector<int>> mat, int k) {
		int n = size(mat);
		auto pq = set<pair<int, int>>();

		for (size_t i = 0; i < n; i++) {
			int s = 0;
			for (auto x : mat[i]) {
				if (!x) break;
				++s;
			}
			pq.insert({ s, i });
			if (size(pq) > k) pq.erase(prev(end(pq)));
			Printer::print(pq);
		}

		vector<int> ans;
		for (auto [_, x] : pq) {
			ans.push_back(x);
		}

		return ans;
	}
	vector<vector<int>> output = {
		{2,0,3},
		{0,2}
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}},
		{{1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0}}
	};
	vector<int> input2 = {
		3,
		2
	};
};