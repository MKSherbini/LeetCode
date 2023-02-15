#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/add-to-array-form-of-integer/

class AddToArrayFormOfInteger
{
public:
	// 23 ms, faster than 94.54% : 27.1 MB, less than 95.67%
	vector<int> solution(vector<int> num, int k) {
		reverse(begin(num), end(num));
		for (size_t i = 0; i < size(num); i++) {
			k += num[i];
			num[i] = k % 10;
			k /= 10;
		}
		while (k) num.push_back(k % 10), k /= 10;
		reverse(begin(num), end(num));

		return num;
	}
	vector<vector<int>> output = {
		{1,2,3,4},
		{4,5,5},
		{1,0,2,1}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,0,0},
		{2,7,4},
		{2,1,5}
	};
	vector<int> input2 = {
		34,
		181,
		806
	};
};