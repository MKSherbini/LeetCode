#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/happy-number/

class HappyNumber
{
public:
	// 0 ms, faster than 100% : 5.7 MB, less than 99.6%
	bool solution(int n) {
		while (n > 5) n = calc(n);
		return n == 1;
	}
	int calc(int n) {
		int res = 0;
		while (n)
			res += (n % 10) * (n % 10), n /= 10;
		return res;
	}
	vector<int> output = {
		true,
		false,
		false,
		false,
		false,
		true,
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		19,
		2,
		4,
		5,
		6,
		1111111,
	};
};