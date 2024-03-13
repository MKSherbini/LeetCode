#pragma once
#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-the-pivot-integer/

class FindThePivotInteger
{
public:
	// 0 ms, faster than 100% : 7.1 MB, less than 87.4%
	int solution(int n) {
		int sum = n * (n + 1) / 2;
		int sum2 = 0;
		while (n) {
			sum2 += n;
			if (sum2 == sum) return n;
			sum -= n;
			n--;
		}

		return -1;
	}
	vector<int> output = {
		6,
		1,
		-1
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		8,
		1,
		4
	};
};