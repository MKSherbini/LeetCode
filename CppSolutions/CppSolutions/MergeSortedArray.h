#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/merge-sorted-array/

class MergeSortedArray
{
public:
	// 0 ms, faster than 100% : 8.9 MB, less than 99.27%
	vector<int> solution(vector<int> nums1, int m, vector<int> nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;

		while (i >= 0 && j >= 0) {
			if (nums1[i] > nums2[j])
				nums1[k--] = nums1[i--];
			else
				nums1[k--] = nums2[j--];
		}

		while (i >= 0)
			nums1[k--] = nums1[i--];

		while (j >= 0)
			nums1[k--] = nums2[j--];

		return nums1;
	}
	vector<vector<int>> output = {
		{1,2,2,3,5,6},
		{1},
		{1}
	};
	static constexpr int const& inputs = 4;
	vector<vector<int>> input1 = {
		{1,2,3,0,0,0},
		{1},
		{0}
	};
	vector<int> input2 = {
		3,
		1,
		0
	};
	vector<vector<int>> input3 = {
		{2,5,6},
		{},
		{1}
	};
	vector<int> input4 = {
		3,
		0,
		1
	};
};