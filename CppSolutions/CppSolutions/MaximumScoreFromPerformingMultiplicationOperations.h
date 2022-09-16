#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

class MaximumScoreFromPerformingMultiplicationOperations
{
public:
	// 351 ms, faster than 96.8% : 50.6 MB, less than 99.6%
	int solution(vector<int> nums, vector<int> multipliers) {
		int n = size(nums);
		int m = size(multipliers);

		vector mem(2, vector(m + 1, 0));

		int cur = 0, other = 1;

		for (int i = m - 1; i >= 0; i--)
		{
			for (int l = 0; l <= i; l++)
			{
				int r = n - 1 - (i - l);
				mem[cur][l] = max(
					mem[other][l + 1] + nums[l] * multipliers[i],
					mem[other][l] + nums[r] * multipliers[i]
				);
			}
			cur = other;
			other = 1 - other;
		}

		Printer::print(mem);

		return mem[other][0];
	}

	// 340 ms, faster than 97.46% : 119.7 MB, less than 72.63%
	int solution3(vector<int> nums, vector<int> multipliers) {
		int n = size(nums);
		int m = size(multipliers);

		vector mem(m + 1, vector(m + 1, 0));

		for (int i = m - 1; i >= 0; i--)
		{
			for (int l = 0; l <= i; l++)
			{
				int r = n - 1 - (i - l);
				mem[i][l] = max(
					mem[i + 1][l + 1] + nums[l] * multipliers[i],
					mem[i + 1][l] + nums[r] * multipliers[i]
				);
			}
		}

		Printer::print(mem);

		return mem[0][0];
	}

	// 423 ms, faster than 91.32% : 121.7 MB, less than 65.69%
	int solution2(vector<int> nums, vector<int> multipliers) {
		this->nums = nums;
		this->multipliers = multipliers;
		int n = size(nums);
		int m = size(multipliers);

		mem.assign(m, vector(m, INT_MIN));

		int ans = 0;

		ans = f(0, 0, n - 1);
		Printer::print(mem);

		return ans;
	}
	vector<int> nums;
	vector<int> multipliers;
	vector<vector<int>> mem;
	int f(int i, int l, int r) {
		if (i == size(multipliers)) return 0;
		if (mem[i][l] != INT_MIN) return mem[i][l];
		Printer::print(i, l, r);

		return  mem[i][l] = max(
			f(i + 1, l + 1, r) + nums[l] * multipliers[i],
			f(i + 1, l, r - 1) + nums[r] * multipliers[i]
		);
	}


	//// WA pick from start or end only
	//int solution(vector<int> nums, vector<int> multipliers) {
	//	int n = size(nums);
	//	int m = size(multipliers);

	//	sort(begin(nums), end(nums));
	//	sort(begin(multipliers), end(multipliers));

	//	Printer::print(nums);
	//	Printer::print(multipliers);

	//	int ans = 0;

	//	int ni = 0, nj = n - 1;

	//	int i = 0;
	//	for (; i < m && multipliers[i] <= 0; i++) {
	//		Printer::print(nums[ni], multipliers[i]);
	//		ans += nums[ni++] * multipliers[i];
	//	}

	//	for (int j = m - 1; j >= i; j--) {
	//		Printer::print(nums[nj], multipliers[j]);
	//		ans += nums[nj--] * multipliers[j];
	//	}

	//	return ans;
	//}
	vector<int> output = {
		14,
		102,
		-1
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3},
		{-5,-3,-3,-2,7,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	vector<vector<int>> input2 = {
		{3,2,1},
		{-10,-5,3,4,6},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
};