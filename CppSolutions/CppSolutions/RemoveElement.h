#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-element/

class RemoveElement
{
public:
	// 0 ms, faster than 100% : 10.3 MB, less than 25.89%
	int solution(vector<int>& nums, int val) {
		int n = size(nums);
		int i = 0, j = n - 1;
		while (i <= j) {
			if (nums[i] == val) {
				swap(nums[i], nums[j]);
				n--;
				j--;
			}
			else {
				i++;
			}
		}
		return n;
	}
	vector<int> output = {
		2,
		5,
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{3,2,2,3},
		{0,1,2,2,3,0,4,2}
	};
	vector<int> input2 = {
		3,
		2
	};
};