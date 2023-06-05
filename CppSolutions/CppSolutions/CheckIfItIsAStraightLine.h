#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/check-if-it-is-a-straight-line/

class CheckIfItIsAStraightLine
{
public:
	// 3 ms, faster than 99.52% : 10.7 MB, less than 7.38%
	bool solution(vector<vector<int>> coordinates) {
		int n = size(coordinates);
		auto calcX = [](vector<int> a, vector<int> b) -> int {
			return (a[0] - b[0]);
		};
		auto calcY = [](vector<int> a, vector<int> b) -> int {
			return (a[1] - b[1]);
		};
		double x = calcX(coordinates[0], coordinates[1]);
		double y = calcY(coordinates[0], coordinates[1]);
		for (size_t i = 2; i < n; i++) {
			if (x * calcY(coordinates[0], coordinates[i]) !=
				y * calcX(coordinates[0], coordinates[i]))
				return false;
		}

		return true;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}},
		{{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}}
	};
};