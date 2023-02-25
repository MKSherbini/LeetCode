#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class BestTimeToBuyAndSellStock
{
public:
	// 119 ms, faster than 96.63% : 93.2 MB, less than 91.9%
	int solution(vector<int>& prices) {
		int mn = prices[0];
		int ans = 0;
		for (int i = 1; i < prices.size(); i++)
			ans = max(ans, prices[i] - mn), mn = min(mn, prices[i]);

		return ans;
	}

	// 112 ms, faster than 89.47% : 97.1 MB, less than 6.92%
	int solution2(vector<int>& prices) {
		if (prices.size() == 1) return 0;

		vector<int> maxes(prices);
		int profit = 0;
		for (int i = prices.size() - 2; i >= 0; i--)
			maxes[i] = max(maxes[i], maxes[i + 1]);

		for (int i = 0; i < prices.size(); i++)
			profit = max(maxes[i] - prices[i], profit);

		return profit;
	}
	vector<int> output = {
		5,
		0,
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{7,1,5,3,6,4},
		{7,6,4,3,1}
	};
};

