#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCuts
{
public:
	// 68 ms, faster than 98.69% : 32.1 MB, less than 95.37%
	int solution(int h, int w, vector<int> horizontalCuts, vector<int> verticalCuts) {
		sort(begin(horizontalCuts), end(horizontalCuts));
		sort(begin(verticalCuts), end(verticalCuts));

		int x = max(horizontalCuts[0], h - horizontalCuts[size(horizontalCuts) - 1]),
			y = max(verticalCuts[0], w - verticalCuts[size(verticalCuts) - 1]);

		for (size_t i = 1; i < size(horizontalCuts); i++)
			x = max(x, horizontalCuts[i] - horizontalCuts[i - 1]);
		for (size_t i = 1; i < size(verticalCuts); i++)
			y = max(y, verticalCuts[i] - verticalCuts[i - 1]);

		return (long long)x * y % (long long)(1e9 + 7);
	}
	vector<int> output = {
		4,
		6,
		9
	};
	static constexpr int const& inputs = 4;
	vector<int> input1 = {
		5,
		5,
		5
	};
	vector<int> input2 = {
		4,
		4,
		4
	};
	vector<vector<int>> input3 = {
		{1,2,4},
		{3,1},
		{3}
	};
	vector<vector<int>> input4 = {
		{1,3},
		{1},
		{3}
	};
};