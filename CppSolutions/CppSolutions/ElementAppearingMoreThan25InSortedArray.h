#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

class ElementAppearingMoreThan25InSortedArray
{
public:
	// 4 ms, faster than 95.9% : 12.6 MB, less than 92.26%
	int solution(vector<int> arr) {
		int n = size(arr), range = n / 4;
		for (size_t i = range; i < n; i++) {
			if (arr[i] == arr[i - range]) return arr[i];
		}

		return -1;
	}
	vector<int> output = {
		6,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,2,6,6,6,6,7,10},
		{1,1}
	};
};