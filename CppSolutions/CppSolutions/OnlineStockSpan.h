#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/make-the-string-great/

class OnlineStockSpan {
public:
	OnlineStockSpan() {

	}

	// 211 ms, faster than 99.32% : 84.1 MB, less than 90.79%
	int next(int price) {
		int ans = 1;

		while (!s.empty() && s.top().first <= price)
			ans += s.top().second, s.pop();

		s.emplace(price, ans);

		return ans;
	}

private:
	stack<pair<int, int>> s;
};
