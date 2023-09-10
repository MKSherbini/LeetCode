#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

class CountAllValidPickupAndDeliveryOptions
{
public:
	// 0 ms, faster than 100% : 5.9 MB, less than 97.11%
	int solution(int n) {
		long long ans = 1;
		int MOD = 1e9 + 7;
		for (size_t i = 2; i <= n; i++) {
			ans *= 2 * i - 1;
			ans %= MOD;
			ans *= i;
			ans %= MOD;
		}

		return ans;
	}
	vector<int> output = {
		1,
		6,
		90
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		1,
		2,
		3
	};
};