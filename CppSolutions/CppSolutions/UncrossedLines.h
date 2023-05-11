#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/uncrossed-lines/

class UncrossedLines
{
public:
	// 49 ms, faster than 11% : 13 MB, less than 63.96%
	int solution(vector<int> nums1, vector<int> nums2) {
		int n = size(nums1), m = size(nums2);
		vector mem(n, vector(m, -1));
		function<int(int, int)> f = [&](int i, int j)-> int {
			if (i == n || j == m) return 0;
			if (mem[i][j] != -1) return mem[i][j];

			int ret = 0;
			if (nums1[i] == nums2[j])
				ret = max(ret, 1 + f(i + 1, j + 1));
			ret = max(ret, f(i + 1, j));
			ret = max(ret, f(i, j + 1));

			return mem[i][j] = ret;
		};

		return f(0, 0);
	}
	vector<int> output = {
		2,
		3,
		2
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,4,2},
		{2,5,1,2,5},
		{1,3,7,1,7,5}
	};
	vector<vector<int>> input2 = {
		{1,2,4},
		{10,5,2,1,5,2},
		{1,9,2,5,1}
	};
};