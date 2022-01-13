#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/climbing-stairs/

class ClimbingStairs
{
public:
	// 0 ms, faster than 100.00% : 5.8 MB, less than 97.36%
	int solution3(int n) {
		if (n <= 2) return n;
		int a = 1;
		int b = 2;
		int ans = 0;
		for (int i = 3; i <= n; i++)
			ans = a + b, a = b, b = ans;
		return ans;
	}

	// 0 ms, faster than 100.00% : 6 MB, less than 36.86%
	int solution2(int n) {
		if (n < 2) return n;
		vector<int> v(n);
		v[0] = 1;
		v[1] = 2;
		for (int i = 2; i < n; i++)
			v[i] = v[i - 1] + v[i - 2];
		return v[n - 1];
	}

	// 0 ms, faster than 100.00% : 5.9 MB, less than 53.52%
	int solution(int n) {
		vector<int> mem(46, -1);
		return dp(n, mem);
	}
	int dp(int n, vector<int>& mem) {
		if (n <= 2) return n;

		if (mem[n] != -1) return mem[n];

		return mem[n] = dp(n - 1, mem) + dp(n - 2, mem);
	}
	vector<int> output = {
		2,
		3,
		1836311903,
	};
	vector<int> input1 = {
		2,
		3,
		45,
	};
};

