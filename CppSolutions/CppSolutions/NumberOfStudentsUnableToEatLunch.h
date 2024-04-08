#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

class NumberOfStudentsUnableToEatLunch
{
public:
	// 0 ms, faster than 100% : 10.6 MB, less than 95.64%
	int solution(vector<int> students, vector<int> sandwiches) {
		int n = size(students);
		int ones = count_if(begin(students), end(students), [](const auto& x) {return x; }), zeros = n - ones;

		for (size_t i = 0; i < n; i++) {
			if (sandwiches[i]) ones--;
			else zeros--;

			if (ones < 0 || zeros < 0) return n - i;
		}

		return 0;
	}
	vector<int> output = {
		0,
		3
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,1,0,0},
		{1,1,1,0,0,1}
	};
	vector<vector<int>> input2 = {
		{0,1,0,1},
		{1,0,0,0,1,1}
	};
};