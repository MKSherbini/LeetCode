#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

class MinimumRoundsToCompleteAllTasks
{
public:
	// 232 ms, faster than 86.32% : 103.6 MB, less than 89.4%
	int solution(vector<int> tasks) {
		unordered_map<int, int> m;
		for (auto t : tasks)
			++m[t];

		Printer::print(m);
		int ans = 0;
		for (auto& p : m) {
			if (p.second == 1) return -1;
			if (p.second % 3) ans += p.second / 3 + 1;
			else ans += p.second / 3;
		}

		return ans;
	}
	vector<int> output = {
		4,
		-1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,2,3,3,2,4,4,4,4,4},
		{2,3,3}
	};
};