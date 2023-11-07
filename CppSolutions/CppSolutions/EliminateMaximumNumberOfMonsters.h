#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/eliminate-maximum-number-of-monsters/?envType=daily-question&envId=2023-11-07

class EliminateMaximumNumberOfMonsters
{
public:
	// 100 ms, faster than 87.73% : 83.1 MB, less than 88.53%
	int solution(vector<int> dist, vector<int> speed) {
		int n = size(speed);
		vector<float> t(n);
		for (size_t i = 0; i < n; i++) {
			t[i] = 1.0 * dist[i] / speed[i];
		}
		sort(begin(t), end(t));

		Printer::print(t);
		int rdyCharge = 0;
		for (size_t i = 0; i < n; i++) {
			if (t[i] <= rdyCharge) return i;
			rdyCharge++;
		}

		return n;
	}
	vector<int> output = {
		3,
		1,
		1
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,3,4},
		{1,1,2,3},
		{3,2,4}
	};
	vector<vector<int>> input2 = {
		{1,1,1},
		{1,1,1,1},
		{5,3,2}
	};
};