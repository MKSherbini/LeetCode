#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-ice-cream-bars/

class MaximumIceCreamBars
{
public:
	// 203 ms, faster than 79.27% : 76.4 MB, less than 95.51%
	int solution(vector<int> costs, int coins) {
		sort(begin(costs), end(costs));
		int n = size(costs);
		int i = 0, ans = 0;

		while (i < n && coins >= costs[i])
			++ans, coins -= costs[i], ++i;

		return ans;
	}
	vector<int> output = {
		4,
		0,
		6
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,3,2,4,1},
		{10,6,8,7,7,8},
		{1,6,3,1,2,5}
	};
	vector<int> input2 = {
		7,
		5,
		20
	};
};