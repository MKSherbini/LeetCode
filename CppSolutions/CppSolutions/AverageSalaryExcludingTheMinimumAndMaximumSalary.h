#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class AverageSalaryExcludingTheMinimumAndMaximumSalary
{
public:
	// 0 ms, faster than 100% : 7 MB, less than 98.74%
	double solution(vector<int> salary) {
		int mx = salary[0], mn = salary[0];
		int ans = 0;
		for (auto x : salary) {
			ans += x;
			if (x > mx) mx = x;
			if (x < mn) mn = x;
		}
		return 1.0 * (ans - mn - mx) / (size(salary) - 2);
	}
	vector<double> output = {
		2500.00000,
		2000.00000
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{4000,3000,1000,2000},
		{1000,2000,3000}
	};
};