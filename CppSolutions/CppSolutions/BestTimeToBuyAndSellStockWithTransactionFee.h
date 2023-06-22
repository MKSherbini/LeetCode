#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class BestTimeToBuyAndSellStockWithTransactionFee
{
public:
	// 119 ms, faster than 83.01% : 54.9 MB, less than 98.47%
	int solution(vector<int> prices, int fee) {
		int n = size(prices);
		vector mem(2, vector(2, 0));
		mem[0][0] = -prices[0] - fee;
		bool cur = 1;

		for (size_t i = 1; i < n; i++) {
			for (size_t bought = 0; bought < 2; bought++) {
				int ret = mem[!cur][bought];

				if (bought) {
					ret = max(ret, prices[i] + mem[!cur][0]);
				}
				else {
					ret = max(ret, -prices[i] - fee + mem[!cur][1]);
				}
				mem[cur][bought] = ret;
			}
			cur = !cur;
		}

		return mem[!cur][1];
	}

	// 237 ms, faster than 55.33% : 90.7 MB, less than 59.4%
	int solution3(vector<int> prices, int fee) {
		int n = size(prices);
		vector mem(n, vector(2, 0));
		mem[0][0] = -prices[0] - fee;

		for (size_t i = 1; i < n; i++) {
			for (size_t bought = 0; bought < 2; bought++) {
				int ret = mem[i - 1][bought];

				if (bought) {
					ret = max(ret, prices[i] + mem[i - 1][0]);
				}
				else {
					ret = max(ret, -prices[i] - fee + mem[i - 1][1]);
				}
				mem[i][bought] = ret;
			}
		}

		return mem[n - 1][1];
	}

	// 287 ms, faster than 6.9% : 106.5 MB, less than 5.73%
	int solution2(vector<int> prices, int fee) {
		int n = size(prices);
		vector mem(n, vector(2, -1));
		function<int(int, bool)> f = [&](int i, bool bought) -> int {
			if (i >= n) return 0;
			if (mem[i][bought] != -1) return mem[i][bought];

			int ret = f(i + 1, bought);

			if (bought) {
				ret = max(ret, prices[i] + f(i + 1, 0));
			}
			else {
				ret = max(ret, -prices[i] - fee + f(i + 1, 1));
			}

			return mem[i][bought] = ret;
		};

		return f(0, 0);
	}
	vector<int> output = {
		8,
		6
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,3,2,8,4,9},
		{1,3,7,5,10,3}
	};
	vector<int> input2 = {
		2,
		3
	};
};