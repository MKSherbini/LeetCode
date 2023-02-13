#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

class CountOddNumbersInAnIntervalRange
{
public:
	// 0 ms, faster than 100% : 5.8 MB, less than 92.26%
	int solution(int low, int high) {
		return (high - low + (low % 2)) / 2 + high % 2;
	}
	vector<int> output = {
		3,
		1
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		3,
		8
	};
	vector<int> input2 = {
		7,
		10
	};
};