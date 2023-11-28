#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/

class NumberOfWaysToDivideALongCorridor
{
public:
	// 101 ms, faster than 98.86% : 30.8 MB, less than 97.71%
	int solution(string corridor) {
		int n = size(corridor);
		const int MOD = 1e9 + 7;
		int seats = count_if(begin(corridor), end(corridor), [](char c) { return c == 'S'; });
		if (!seats || seats % 2) return 0;
		long long ans = 1;
		int i = 0;
		while (seats > 2) {
			seats -= 2;
			int c = 2;
			while (c) {
				if (corridor[i++] == 'S') c--;
			}
			int lastSeat = i;
			while (corridor[i] != 'S') {
				i++;
			}
			ans *= i - lastSeat + 1;
			ans %= MOD;
		}

		return ans;
	}
	vector<int> output = {
		3,
		1,
		0
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"SSPPSPS",
		"PPSPSP",
		"S"
	};
};