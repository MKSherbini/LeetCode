#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-eventual-safe-states/

class FindEventualSafeStates
{
public:
	// 157 ms, faster than 92.52% : 47 MB, less than 90.67%
	vector<int> solution(vector<vector<int>> graph) {
		int n = size(graph);
		vector<int> s(n, -1);

		function<bool(int)> f = [&](int i) -> bool {
			if (s[i] != -1) return s[i];
			if (empty(graph[i])) return s[i] = 1;
			s[i] = -2;
			bool ret = 1;

			for (auto& j : graph[i]) {
				if (s[j] == -2) return s[i] = false;
				ret &= f(j);
				if (!ret) return s[i] = ret;
			}

			return s[i] = ret;
		};

		vector<int> ans;
		for (size_t i = 0; i < n; i++) {
			if (f(i)) ans.push_back(i);
		}
		Printer::print(s);

		return ans;
	}
	vector<vector<int>> output = {
		{2,4,5,6},
		{4}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2},{2,3},{5},{0},{5},{},{}},
		{{1,2,3,4},{1,2},{3,4},{0,4},{}}
	};
};