#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/peak-index-in-a-mountain-array/

class PeakIndexInAMountainArray
{
public:
	// 109 ms, faster than 96.21% : 59.6 MB, less than 88.25%
	int solution(vector<int> arr) {
		int l = 0, r = size(arr) - 1;

		while (l < r) {
			int md = l + (r - l) / 2;

			if (arr[md] > arr[md + 1])
				r = md;
			else
				l = md + 1;
		}

		return l;
	}
	vector<int> output = {
		1,
		1,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{0,1,0},
		{0,2,1,0},
		{0,10,5,2}
	};
};