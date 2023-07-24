#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/powx-n/

class PowXN
{
public:
	// 0 ms, faster than 100% : 5.8 MB, less than 99.91%
	double solution(double x, int n) {
		function<double(double, int)> f = [&](double x, int n) -> double {
			if (n == 0) return 1;
			if (n % 2) return n < 0 ? f(x, n + 1) * 1 / x : f(x, n - 1) * x;
			return f(x * x, n / 2);
		};

		return f(x, n);
	}
	vector<double> output = {
		1024.00000,
		9.26100,
		0.25000
	};
	static constexpr int const& inputs = 2;
	vector<double> input1 = {
		2.00000,
		2.10000,
		2.00000
	};
	vector<int> input2 = {
		10,
		3,
		-2
	};
};