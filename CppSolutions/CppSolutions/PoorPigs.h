#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/poor-pigs/

class PoorPigs
{
public:
	// 0 ms, faster than 100% : 6.4 MB, less than 40.68%
	int solution(int buckets, int minutesToDie, int minutesToTest) {
		int tries = minutesToTest / minutesToDie;
		int pigs = 0;
		while (pow(tries + 1, pigs) < buckets)
			pigs++;

		return pigs;
	}
	vector<int> output = {
		2,
		2
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		4,
		4
	};
	vector<int> input2 = {
		15,
		15
	};
	vector<int> input3 = {
		15,
		30
	};
};