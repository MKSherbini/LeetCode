#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/min-cost-climbing-stairs/

class MinCostClimbingStairs
{
public:
	// 4 ms, faster than 89.59% : 13.6 MB, less than 79.79%
	int solution(vector<int> cost) {
		cost.push_back(0);
		return min(f(cost, 0), f(cost, 1));
	}

	int f(vector<int>& cost, int i) {
		int n = cost.size();
		int ans = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

		for (; i < n; i++) {
			while (!pq.empty() && pq.top().second < i - 2)
				pq.pop();

			ans = cost[i] + (pq.empty() ? 0 : pq.top().first);
			pq.push({ ans, i });
		}
		Printer::print(ans);
		return ans;
	}
	vector<int> output = {
		15,
		6
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{10,15,20},
		{1,100,1,1,1,100,1,1,100,1}
	};
};