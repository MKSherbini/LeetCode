#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-cost-for-tickets/

class MinimumCostForTickets
{
public:
	// 0 ms, faster than 100% : 9.5 MB, less than 81.02%
	int solution(vector<int> days, vector<int> costs) {
		int n = size(days);
		vector<int> mem(365, -1);
		vector<int> indexDays(365);
		for (auto d : days)
			indexDays[d - 1] = 1;

		return f(indexDays, costs, mem, 0);
	}
	int f(vector<int>& days, vector<int>& costs, vector<int>& mem, int i) {
		if (i >= 365) return 0;
		while (!days[i]) {
			++i;
			if (i >= 365) return 0;
		}

		if (mem[i] != -1) return mem[i];

		int ret = OO;
		ret = min(ret, f(days, costs, mem, i + 1) + costs[0]);
		ret = min(ret, f(days, costs, mem, i + 7) + costs[1]);
		ret = min(ret, f(days, costs, mem, i + 30) + costs[2]);

		return mem[i] = ret;
	}

	const int OO = 1e7;

	vector<int> output = {
		11,
		17
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,4,6,7,8,20},
		{1,2,3,4,5,6,7,8,9,10,30,31}
	};
	vector<vector<int>> input2 = {
		{2,7,15},
		{2,7,15}
	};
};