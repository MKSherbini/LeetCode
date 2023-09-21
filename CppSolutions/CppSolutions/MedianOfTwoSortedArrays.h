#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/median-of-two-sorted-arrays/?envType=daily-question&envId=2023-09-21

class MedianOfTwoSortedArrays
{
public:
	// 11 ms, faster than 99.26% : 89.4 MB, less than 57.17%
	double solution(vector<int> nums1, vector<int> nums2) {
		int n = size(nums1), m = size(nums2);
		int goal = (n + m) / 2;
		int i = 0, j = 0;
		int g1 = -1, g2 = -1;
		while (i < n && j < m && goal-- >= 0) {
			if (nums1[i] < nums2[j]) {
				if (g1 == -1) g1 = nums1[i];
				else g2 = g1, g1 = nums1[i];
				i++;
			}
			else {
				if (g1 == -1) g1 = nums2[j];
				else g2 = g1, g1 = nums2[j];
				j++;
			}
		}

		while (i < n && goal-- >= 0) {
			if (g1 == -1) g1 = nums1[i];
			else g2 = g1, g1 = nums1[i];
			i++;
		}

		while (j < m && goal-- >= 0) {
			if (g1 == -1) g1 = nums2[j];
			else g2 = g1, g1 = nums2[j];
			j++;
		}

		return (n + m) % 2 ? g1 : (g1 + g2) / 2.0;
	}

	double solution2(vector<int> nums1, vector<int> nums2) {
		int n = size(nums1), m = size(nums2);
		int goal = (n + m) / 2;
		int l1 = 0, r1 = n - 1, l2 = 0, r2 = m - 1;
		while (true) {
			int md1 = (l1 + r1) / 2, md2 = (l2 + r2) / 2;

			if (nums1[md1] < nums2[md2]) {

			}
		}
	}
	vector<double> output = {
		2.00000,
		2.50000
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,3},
		{1,2}
	};
	vector<vector<int>> input2 = {
		{2},
		{3,4}
	};
};