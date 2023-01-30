#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/n-th-tribonacci-number/

class NThTribonacciNumber
{
public:
	// 0 ms, faster than 100% : 5.9 MB, less than 94.16%
	int solution(int n) {
		vector<int> v = { 0,0,1,1 };
		if (n < 3) return v[n + 1];

		for (size_t i = 2; i < n; i++) {
			swap(v[3], v[2]);
			swap(v[3], v[1]);
			swap(v[3], v[0]);
			v[3] = v[0] + v[1] + v[2];
		}
		return v[3];
	}
	vector<int> output = {
		4,
		1389537
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		4,
		25
	};
};