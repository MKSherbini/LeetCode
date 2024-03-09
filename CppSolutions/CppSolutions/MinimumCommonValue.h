#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-common-value/

class MinimumCommonValue
{
public:
	// 56 ms, faster than 95.98% : 52.8 MB, less than 73.96%
	int solution(vector<int> nums1, vector<int> nums2) {
		int i = 0, j = 0, n = size(nums1), m = size(nums2);

		while (i < n && j < m) {
			if (nums1[i] < nums2[j])
				i++;
			else if (nums1[i] > nums2[j])
				j++;
			else return nums1[i];
		}

		return -1;
	}
	vector<int> output = {
		2,
		2
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3},
		{1,2,3,6}
	};
	vector<vector<int>> input2 = {
		{2,4},
		{2,3,4,5}
	};
};