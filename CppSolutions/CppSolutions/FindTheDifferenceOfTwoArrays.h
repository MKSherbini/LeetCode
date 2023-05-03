#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-the-difference-of-two-arrays/

class FindTheDifferenceOfTwoArrays
{
public:
	// 25 ms, faster than 99.25% : 26.2 MB, less than 99.1%
	vector<vector<int>> solution(vector<int> nums1, vector<int> nums2) {
		vector<vector<int>> ans(2);

		sort(begin(nums1), end(nums1));
		sort(begin(nums2), end(nums2));

		int i = size(nums1) - 1, j = size(nums2) - 1;

		while (i >= 0 && j >= 0) {
			if (nums1[i] > nums2[j]) {
				ans[0].push_back(nums1[i]);
				int x = nums1[i];
				while (i >= 0 && nums1[i] == x) {
					i--;
				}
			}
			else if (nums1[i] < nums2[j]) {
				ans[1].push_back(nums2[j]);
				int x = nums2[j];
				while (j >= 0 && nums2[j] == x) {
					j--;
				}
			}
			else if (nums1[i] == nums2[j]) {
				int x = nums1[i];

				while (i >= 0 && nums1[i] == x) {
					i--;
				}
				while (j >= 0 && nums2[j] == x) {
					j--;
				}
			}
		}
		while (i >= 0) {
			ans[0].push_back(nums1[i]);
			int x = nums1[i];
			while (i >= 0 && nums1[i] == x) {
				i--;
			}
		}
		while (j >= 0) {
			ans[1].push_back(nums2[j]);
			int x = nums2[j];
			while (j >= 0 && nums2[j] == x) {
				j--;
			}
		}


		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{1,3},{4,6}},
		{{3},{}}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3},
		{1,2,3,3}
	};
	vector<vector<int>> input2 = {
		{2,4,6},
		{1,1,2,2}
	};
};