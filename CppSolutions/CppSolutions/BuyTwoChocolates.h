#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/buy-two-chocolates/

class BuyTwoChocolates
{
public:
	// 3 ms, faster than 98.75% : 46.9 MB, less than 94.77%
	int solution(vector<int> prices, int money) {
		sort(begin(prices), end(prices));
		return prices[0] + prices[1] <= money ? money - prices[0] - prices[1] : money;
	}
	vector<int> output = {
		0,
		3
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,2},
		{3,2,3}
	};
	vector<int> input2 = {
		3,
		3
	};
};