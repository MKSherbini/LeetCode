#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class SubtractTheProductAndSumOfDigitsOfAnInteger
{
public:
	// 0 ms, faster than 100.00% : 5.8 MB, less than 95.82%
	int solution(int n) {
		int prod = 1, sum = 0;
		while (n)
			prod *= n % 10, sum += n % 10, n /= 10;

		return prod - sum;
	}
	vector<int> output = {
		15,
		21,
		-1,
	};
	vector<int> input1 = {
		234,
		4421,
		21,
	};
};

