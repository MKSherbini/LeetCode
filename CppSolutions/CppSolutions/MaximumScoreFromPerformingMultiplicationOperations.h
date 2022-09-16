#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

class MaximumScoreFromPerformingMultiplicationOperations
{
public:
	// 423 ms, faster than 91.32% : 121.7 MB, less than 65.69%
	int solution(vector<int> nums, vector<int> multipliers) {
		this->nums = nums;
		this->multipliers = multipliers;
		int n = size(nums);
		int m = size(multipliers);

		mem.assign(m, vector(m, INT_MIN));

		int ans = 0;

		ans = f(0, 0, n - 1);

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