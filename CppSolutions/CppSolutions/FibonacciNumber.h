#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/fibonacci-number/

class FibonacciNumber
{
public:
	// 16 ms, faster than 13.67% : 5.7 MB, less than 96.47%
	int solution2(int n) {
		if (n <= 1) return n;
		return (dp[n - 1] != 0 ? dp[n - 1] : solution2(n - 1))
			+ (dp[n - 2] != 0 ? dp[n - 2] : solution2(n - 2));
	}
	// 0 ms, faster than 100.00% : 5.9 MB, less than 79.67%
	int solution(int n) {
		if (n <= 1) return n;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[n];
	}
	int dp[31];
	vector<int> output = {
		1,
		2,
		3,
		832040,
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		2,
		3,
		4,
		30,
	};
};

