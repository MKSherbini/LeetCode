#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class BestTimeToBuyAndSellStockWithCooldown
{
public:
	// 0 ms, faster than 100% : 11.1 MB, less than 91.07%
	int solution(vector<int> prices) {
		const int n = size(prices);
		auto mem = vector(3, vector(2, 0));
		mem[1][0] = prices[n - 1];

		for (int i = n - 2; i >= 0; i--) {
			for (size_t canBuy = 0; canBuy < 2; canBuy++)
				mem[0][canBuy] = max(mem[0][canBuy], mem[1][canBuy]);
			mem[0][1] = max(mem[0][1], -prices[i] + mem[1][0]);

			mem[0][0] = max(mem[0][0], prices[i] + (i + 2 == n ? mem[1][1] : mem[2][1]));
			swap(mem[2], mem[1]);
			swap(mem[0], mem[1]);
		}

		return mem[1][1];
	}

	// 0 ms, faster than 100% : 11.7 MB, less than 53.35%
	int solution1(vector<int> prices) {
		const int n = size(prices);
		auto mem = vector(n, vector(2, 0));
		mem[n - 1][0] = prices[n - 1];

		for (int i = n - 2; i >= 0; i--) {
			for (size_t canBuy = 0; canBuy < 2; canBuy++)
				mem[i][canBuy] = max(mem[i][canBuy], mem[i + 1][canBuy]);
			mem[i][1] = max(mem[i][1], -prices[i] + mem[i + 1][0]);

			mem[i][0] = max(mem[i][0], prices[i] + (i + 2 == n ? mem[i + 1][1] : mem[i + 2][1]));
		}

		return mem[0][1];
	}

	// 0 ms, faster than 100% : 12 MB, less than 25.35%
	int solution2(vector<int> prices) {
		auto mem = vector(size(prices), vector(2, -1));
		return f(prices, mem, 0, 1);
	}

	int f(vector<int>& prices, vector<vector<int>>& mem, int i, int canBuy) {
		if (i >= size(prices)) return 0;
		if (mem[i][canBuy] != -1) return mem[i][canBuy];

		int mx = f(prices, mem, i + 1, canBuy);

		if (canBuy)
			mx = max(mx, -prices[i] + f(prices, mem, i + 1, 0));
		else
			mx = max(mx, prices[i] + f(prices, mem, i + 2, 1));

		return mem[i][canBuy] = mx;
	}

	vector<int> output = {
		3,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,0,2},
		{1}
	};
};