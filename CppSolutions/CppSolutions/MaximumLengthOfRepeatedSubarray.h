#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class MaximumLengthOfRepeatedSubarray
{
public:
	// 309 ms, faster than 83.18% : 11.8 MB, less than 97.9%
	int solution(vector<int> nums1, vector<int> nums2) {
		int n = size(nums1), m = size(nums2);
		vector<int> mem(m + 1, 0);
		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				if (nums1[i] == nums2[j])
					mem[j + 1] = 1 + mem[j];
				else
					mem[j + 1] = 0;
				ans = max(ans, mem[j + 1]);
			}
			Printer::print(mem);

		}
		return ans;
	}

	// 474 ms, faster than 53.38% : 109.1 MB, less than 54.76%
	int solution4(vector<int> nums1, vector<int> nums2) {
		int n = size(nums1), m = size(nums2);
		vector<vector<int>> mem(n + 1, vector<int>(m + 1, 0));
		int ans = 0;

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				if (nums1[i] == nums2[j])
					mem[i][j] = 1 + mem[i + 1][j + 1];
				else
					mem[i][j] = 0;
				ans = max(ans, mem[i][j]);
			}
		}
		Printer::print(mem);
		return ans;
	}

	// Still TLE 
	int solution3(vector<int> nums1, vector<int> nums2) {
		vector<vector<int>> v(101);
		for (size_t i = 0; i < size(nums2); i++)
			v[nums2[i]].push_back(i);
		int ans = 0;
		for (size_t i = 0; i < size(nums1); i++)
		{
			for (auto j : v[nums1[i]])
			{
				int len = 0;
				for (size_t jj = j, ii = i; jj < size(nums2) && ii < size(nums1); jj++, ii++)
				{
					if (nums1[ii] == nums2[jj]) len++;
					else break;
				}
				ans = max(ans, len);
			}
		}
		return ans;
	}

	// TLE ofc
	int solution2(vector<int> nums1, vector<int> nums2) {
		int ans = 0;
		for (size_t i = 0; i < size(nums1); i++)
		{
			for (size_t j = 0; j < size(nums2); j++)
			{
				int len = 0;
				for (size_t jj = j, ii = i; jj < size(nums2) && ii < size(nums1); jj++, ii++)
				{
					if (nums1[ii] == nums2[jj]) len++;
					else break;
				}
				ans = max(ans, len);
			}
		}
		return ans;
	}
	vector<int> output = {
		3,
		5
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,2,1},
		{0,0,0,0,0}
	};
	vector<vector<int>> input2 = {
		{3,2,1,4,7},
		{0,0,0,0,0}
	};
};