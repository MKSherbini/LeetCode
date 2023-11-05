#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-the-winner-of-an-array-game/?envType=daily-question&envId=2023-11-05

class FindTheWinnerOfAnArrayGame
{
public:
	// 73 ms, faster than 93.52% : 63.4 MB, less than 86.11%
	int solution(vector<int> arr, int k) {
		int n = size(arr);
		if (k >= n - 1) return *max_element(begin(arr), end(arr));

		int mx = arr[0], c = 0;
		for (size_t i = 1; i < n; i++) {
			if (mx > arr[i]) c++;
			else c = 1, mx = arr[i];
			if (c == k) return mx;
		}

		return *max_element(begin(arr), end(arr));
	}
	vector<int> output = {
		5,
		3
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{2,1,3,5,4,6,7},
		{3,2,1}
	};
	vector<int> input2 = {
		2,
		10
	};
};