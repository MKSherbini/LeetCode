#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/kth-missing-positive-number/

class KthMissingPositiveNumber
{
public:
	// 0 ms, faster than 100% : 9.4 MB, less than 100%
	int solution(vector<int> arr, int k) {
		int i = 0, j = size(arr) - 1;

		while (i <= j) {
			int md = i + (j - i) / 2;
			Printer::print(i, j);
			if (arr[md] - 1 < md + k) {
				if (i == md) break;
				i = md;
			}
			else {
				if (j == md) break;
				j = md;
			}
		}
		if (arr[j] - 1 < j + k)
			return arr[j] + k - (arr[j] - j - 1);
		if (arr[i] - 1 < i + k)
			return arr[i] + k - (arr[i] - i - 1);
		return k;
	}
	vector<int> output = {
		9,
		6,
		1
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{2,3,4,7,11},
		{1,2,3,4},
		{2}
	};
	vector<int> input2 = {
		5,
		2,
		1
	};
};