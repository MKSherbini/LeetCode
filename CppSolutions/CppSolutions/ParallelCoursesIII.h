#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/parallel-courses-iii/

class ParallelCoursesIII
{
public:
	// 294 ms, faster than 94.54% : 151.6 MB, less than 19.86%
	int solution(int n, vector<vector<int>> relations, vector<int> time) {
		vector adj(n, vector<int>());
		for (auto& rel : relations) {
			adj[rel[1] - 1].push_back(rel[0] - 1);
		}

		vector<int> mem(n, -1);
		function<int(int)> f = [&](int i) -> int {
			if (mem[i] != -1) return mem[i];

			int ret = 0;
			for (auto j : adj[i]) {
				ret = max(ret, f(j));
			}

			return mem[i] = ret + time[i];
		};

		int ans = 0;
		for (size_t i = 0; i < n; i++) {
			ans = max(ans, f(i));
		}

		return ans;
	}
	vector<int> output = {
		8,
		12
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		3,
		5
	};
	vector<vector<vector<int>>> input2 = {
		{{1,3},{2,3}},
		{{1,5},{2,5},{3,5},{3,4},{4,5}}
	};
	vector<vector<int>> input3 = {
		{3,2,5},
		{1,2,3,4,5}
	};
};