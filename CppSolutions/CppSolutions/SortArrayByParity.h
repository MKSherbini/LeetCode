#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sort-array-by-parity/

class SortArrayByParity
{
public:
	// 0 ms, faster than 100% : 16.4 MB, less than 46.32%
	vector<int> solution(vector<int> nums) {
		int n = size(nums);
		auto findNextEven = [&](int st) {
			int nxtEven = -1;
			for (size_t i = st; i < n; i++) {
				if (nums[i] % 2 == 0) {
					nxtEven = i;
					break;
				}
			}
			return nxtEven;
		};

		int nxtEven = findNextEven(0);
		if (nxtEven == -1) return nums;

		for (size_t i = 0; i < n; i++) {
			if (nums[i] % 2) {
				swap(nums[nxtEven], nums[i]);
				nxtEven = findNextEven(nxtEven + 1);
			}
			else if (i == nxtEven) {
				nxtEven = findNextEven(nxtEven + 1);
			}

			if (nxtEven == -1) break;
		}

		return nums;
	}
	vector<vector<int>> output = {
		{2,4,3,1},
		{0},
		{0,1}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,1,2,4},
		{0},
		{0,1}
	};
};