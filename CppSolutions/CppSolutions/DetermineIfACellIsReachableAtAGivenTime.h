#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/

class DetermineIfACellIsReachableAtAGivenTime
{
public:
	// 0 ms, faster than 100% : 6.2 MB, less than 10.74%
	bool solution(int sx, int sy, int fx, int fy, int t) {
		int dx = abs(sx - fx), dy = abs(sy - fy);
		return dx == 0 && dy == 0 ? t != 1 : t >= max(dx, dy);
	}
	vector<bool> output = {
		true,
		false
	};
	static constexpr int const& inputs = 5;
	vector<int> input1 = {
		2,
		3
	};
	vector<int> input2 = {
		4,
		1
	};
	vector<int> input3 = {
		7,
		7
	};
	vector<int> input4 = {
		7,
		3
	};
	vector<int> input5 = {
		6,
		3
	};
};