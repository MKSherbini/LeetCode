#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class BestTimeToBuyAndSellStockIV
{
public:
	// 11 ms, faster than 79.68% : 10.8 MB, less than 94.31%
	int solution(int k, vector<int> prices) {
		vector<vector<vector<int>>> mem(2, vector(2, vector(k + 1, 0)));
		int cur = 0, other = 1;
		for (int i = size(prices) - 1; i >= 0; i--)
		{
			cur = other;
			other = 1 - cur;
			for (int bought = 0; bought < 2; bought++)
			{
				for (int trades = k - 1; trades >= 0; trades--)
				{
					int ret = mem[other][bought][trades];
					if (bought == 0)
						ret = max(ret, -prices[i] + mem[other][1][trades]);
					else
						ret = max(ret, prices[i] + mem[other][0][trades + 1]);

					mem[cur][bought][trades] = ret;
				}
			}
		}
		Printer::print(mem);
		return mem[cur][0][0];
	}
	// 13 ms, faster than 71.79% : 13 MB, less than 38.1%
	int solution3(int k, vector<int> prices) {
		vector<vector<vector<int>>> mem(size(prices) + 1, vector(2, vector(k + 1, 0)));

		for (int i = size(prices) - 1; i >= 0; i--)
		{
			for (int bought = 0; bought < 2; bought++)
			{
				for (int trades = k - 1; trades >= 0; trades--)
				{
					int ret = mem[i + 1][bought][trades];
					if (bought == 0)
						ret = max(ret, -prices[i] + mem[i + 1][1][trades]);
					else
						ret = max(ret, prices[i] + mem[i + 1][0][trades + 1]);

					mem[i][bought][trades] = ret;
				}
			}
		}
		Printer::print(mem);
		return mem[0][0][0];
	}

	// 22 ms, faster than 45.96% : 13 MB, less than 35.44%
	int solution2(int k, vector<int> prices) {
		mem.assign(size(prices), vector(2, vector(k + 1, -1)));
		this->k = k;
		this->prices = prices;
		int ans = f(0, -1, 0);
		cout << endl;
		Printer::print(mem);
		return ans;
	}
	int f(int i, int bought, int trades) {
		if (trades == k || i == size(prices)) return 0;
		if (mem[i][bought == -1][trades] != -1) return mem[i][bought == -1][trades];

		int ret = 0;
		ret = max(ret, f(i + 1, bought, trades));
		if (bought == -1)
			ret = max(ret, -prices[i] + f(i + 1, i, trades));
		else if (prices[i] > prices[bought])
			ret = max(ret, prices[i] + f(i + 1, -1, trades + 1)); // why not prices[i] - prices[bought]

		Printer::print(i, bought, trades, ret);

		return mem[i][bought == -1][trades] = ret;
	}
	int k;
	vector<int> prices;
	vector<vector<vector<int>>> mem;

	vector<int> output = {
		2,
		7,
		15,
		1
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		2,
		2,
		3,
		1
	};
	vector<vector<int>> input2 = {
		{2,4,1},
		{3,2,6,5,0,3},
		{2,6,8,7,8,7,9,4,1,2,4,5,8},
		{1,2}
	};
};