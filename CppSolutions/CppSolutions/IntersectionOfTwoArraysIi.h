#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/intersection-of-two-arrays-ii/

class IntersectionOfTwoArraysIi
{
public:
	// 0 ms, faster than 100% : 9.9 MB, less than 99.48%
	vector<int> solution(vector<int> nums1, vector<int> nums2) {
		sort(begin(nums1), end(nums1));
		sort(begin(nums2), end(nums2));
		vector<int> ans;

		int i = 0, j = 0;

		while (i < nums1.size() && j < nums2.size())
		{

		}

		return ans;
	}

	// 0 ms, faster than 100% : 9.9 MB, less than 99.48%
	vector<int> solution2(vector<int> nums1, vector<int> nums2) {
		int freq[1001] = { 0 };

		for (size_t i = 0; i < nums1.size(); i++)
			freq[nums1[i]]++;

		vector<int> ans;

		for (size_t i = 0; i < nums2.size(); i++)
			if (freq[nums2[i]]) ans.push_back(nums2[i]), freq[nums2[i]]--;

		return ans;
	}
	vector<vector<int>> output = {
		{2,2},
		{4,9}
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