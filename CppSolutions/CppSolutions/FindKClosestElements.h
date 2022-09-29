#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-k-closest-elements/

class FindKClosestElements
{
public:
	// 30 ms, faster than 99.76% : 30.9 MB, less than 98.27%
	vector<int> solution(vector<int> arr, int k, int x) {
		int n = size(arr);
		int i = lower_bound(begin(arr), end(arr), x) - begin(arr);
		if (i == n || i > 0 && abs(x - arr[i - 1]) <= abs(x - arr[i])) i--;
		int j = i;
		--k;

		while (k > 0 && i > 0 && j < n - 1)
		{
			Printer::print(i, j);
			--k;

			if (x - arr[i - 1] <= arr[j + 1] - x) --i;
			else ++j;
		}

		Printer::print(k, i, j);
		i = max(i - k, 0);
		j = min(j + k, n - 1);

		return { begin(arr) + i, begin(arr) + j + 1 };
	}
	vector<vector<int>> output = {
		{1,2,3,4},
		{2,3,4,4},
		{1,2,3,4},
		{0,1,1,1,2,3,6,7,8},
		{3,3,4}
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{1,2,3,4,5},
		{1,2,3,4,4,5},
		{1,2,3,4,5},
		{0,1,1,1,2,3,6,7,8,9},
		{0,0,1,2,3,3,4,7,7,8}
	};
	vector<int> input2 = {
		4,
		4,
		4,
		9,
		3
	};
	vector<int> input3 = {
		3,
		3,
		-1,
		4,
		5
	};
};