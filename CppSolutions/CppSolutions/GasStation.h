#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/gas-station/

class GasStation
{
public:
	// 69 ms, faster than 99.52% : 69.4 MB, less than 90.73%
	int solution(vector<int> gas, vector<int> cost) {
		int n = size(gas);
		for (size_t i = 0; i < n; i++) {
			gas[i] -= cost[i];
		}
		Printer::print(gas);

		int i = n * 2 - 1;
		int mxSoFar = 0, mx = INT_MIN, mxI = -1;
		while (i >= 0) {
			mxSoFar += gas[i % n];
			if (mx < mxSoFar) mx = mxSoFar, mxI = i;
			Printer::print(i, mxSoFar, mx, mxI);
			if (mxSoFar < 0) mxSoFar = 0;
			--i;
		}

		int sum = 0;
		for (size_t i = 0; i < n; i++) {
			sum += gas[(mxI + i) % n];
			if (sum < 0) return -1;
		}

		return mxI % n;
	}
	vector<int> output = {
		3,
		4,
		3,
		-1
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,4,5},
		{5,1,2,3,4},
		{1,2,3,4,5,6},
		{2,3,4}
	};
	vector<vector<int>> input2 = {
		{3,4,5,1,2},
		{2,3,4,5,1},
		{4,5,6,1,2,3},
		{3,4,3}
	};
};