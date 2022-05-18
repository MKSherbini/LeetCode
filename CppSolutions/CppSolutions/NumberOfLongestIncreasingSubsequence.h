#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class NumberOfLongestIncreasingSubsequence
{
public:
	// 218 ms, faster than 34.89% : 13.1 MB, less than 93.9%
	int solution(vector<int> nums) {
		int sz = nums.size();

		if (sz <= 1) return sz;

		vector<int> cnts(sz, 1);
		vector<int> lens(sz, 1);
		int mxLen = 1;

		for (size_t i = 0; i < sz; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				if (nums[j] >= nums[i]) continue;

				if (lens[j] + 1 == lens[i])
					cnts[i] += cnts[j];
				else if (lens[j] + 1 > lens[i])
					lens[i] = lens[j] + 1, cnts[i] = cnts[j];


				if (mxLen < lens[i])
					mxLen = lens[i];
			}
		}

		//Printer::print(lens, cnts);

		int ans = 0;
		for (size_t i = 0; i < sz; i++)
			if (mxLen == lens[i])
				ans += cnts[i];

		return ans;
	}

	// WA: need to handle intermediate counts
	int solution2(vector<int> nums) {
		vector<int> mem(nums.size(), -1);
		int ret = 1, cnt = 1;
		curse(nums, mem, 0, ret, cnt);
		Printer::print(mem);
		return cnt;
	}
	int curse(vector<int>& nums, vector<int>& mem, int i, int& mx, int& cnt) {
		if (i + 1 == nums.size()) return 1;
		if (mem[i] != -1) return mem[i];

		int ret = 0, maxHere = 1;

		for (int j = i + 1; j < nums.size(); j++) {
			ret = curse(nums, mem, j, mx, cnt);
			if (nums[i] < nums[j]
				&& ret + 1 > maxHere)
				maxHere = ret + 1;
		}

		if (mx < maxHere)
			mx = maxHere, cnt = 1;

		if (mx == maxHere)
			cnt++;


		return mem[i] = maxHere;
	}
	vector<int> output = {
		2,
		5,
		3
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,3,5,4,7},
		{2,2,2,2,2},
		{1,2,4,3,5,4,7,2}
	};
};