#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class RemoveDuplicatesFromSortedArray
{
public:
	// 7 ms, faster than 98.66% : 18.2 MB, less than 92.95%
	int solution(vector<int>& nums) {
		int n = size(nums);
		int i = 0, j = 1;

		while (j < n) {
			Printer::print(i, j);
			Printer::print(nums);
			if (nums[i] == nums[j]) j++;
			else if (i + 1 == j)
				++i, ++j;
			else {
				++i;
				swap(nums[i], nums[j]);
				++j;
			}
		}
		return i + 1;
	}
	vector<int> output = {
		2,
		5
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,1,2},
		{0,0,1,1,1,2,2,3,3,4}
	};
};