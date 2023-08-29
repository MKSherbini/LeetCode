#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-penalty-for-a-shop/

class MinimumPenaltyForAShop
{
public:
	// 15 ms, faster than 99.36% : 10.6 MB, less than 97.17%
	int solution(string customers) {
		int n = size(customers);
		int y = 0;
		for (auto c : customers)
			y += c == 'Y';

		int no = 0;
		int ans = 0, pen = y;
		for (size_t i = 0; i < n; i++) {
			y -= customers[i] == 'Y';
			no += customers[i] == 'N';

			if (y + no < pen) {
				pen = y + no;
				ans = i + 1;
			}
		}

		return ans;
	}
	vector<int> output = {
		2,
		0,
		4
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"YYNY",
		"NNNNN",
		"YYYY"
	};
};