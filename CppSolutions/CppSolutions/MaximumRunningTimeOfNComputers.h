#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-running-time-of-n-computers/

class MaximumRunningTimeOfNComputers
{
public:
	// 114 ms, faster than 100% : 55.7 MB, less than 98.56%
	int solution(int n, vector<int> batteries) {
		sort(begin(batteries), end(batteries));
		long long sum = accumulate(begin(batteries), end(batteries), 0LL);

		for (int i = size(batteries) - 1; i >= 0; i--) {
			if (batteries[i] <= sum / n) return sum / n;

			sum -= batteries[i];
			n--;
		}

		return -1;
	}
	vector<int> output = {
		4,
		2
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		2,
		2
	};
	vector<vector<int>> input2 = {
		{3,3,3},
		{1,1,1,1}
	};
};