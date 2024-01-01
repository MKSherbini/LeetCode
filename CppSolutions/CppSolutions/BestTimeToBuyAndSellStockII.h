#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class BestTimeToBuyAndSellStockII
{
public:
	// 0 ms, faster than 100% : 13.3 MB, less than 93.92%
	int solution(vector<int> prices) {
		int n = size(prices);

		int ans = 0;
		for (size_t i = 1; i < n; i++) {
			ans += max(0, prices[i] - prices[i - 1]);
		}

		return ans;
	}
	vector<int> output = {
		7,
		4,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{7,1,5,3,6,4},
		{1,2,3,4,5},
		{7,6,4,3,1}
	};
};