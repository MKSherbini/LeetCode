#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/intersection-of-two-arrays/

class IntersectionOfTwoArrays
{
public:
	// 3 ms, faster than 96.17% : 9.8 MB, less than 99.72%
	vector<int> solution(vector<int> nums1, vector<int> nums2) {
		sort(begin(nums1), end(nums1));
		sort(begin(nums2), end(nums2));

		vector<int> ans;

		int i = 0, j = 0;
		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] == nums2[j]) {
				ans.push_back(nums1[i]);
				while (i < nums1.size() && nums1[i] == ans[ans.size() - 1]) i++;
				while (j < nums2.size() && nums2[j] == ans[ans.size() - 1]) j++;
			}
			else if (nums1[i] < nums2[j])
				i++;
			else
				j++;
		}

		return ans;
	}
	vector<vector<int>> output = {
		{2},
		{9,4}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,2,1},
		{4,9,5}
	};
	vector<vector<int>> input2 = {
		{2,2},
		{9,4,9,8,4}
	};
};