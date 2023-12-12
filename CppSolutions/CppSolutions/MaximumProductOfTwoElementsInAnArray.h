#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

class MaximumProductOfTwoElementsInAnArray
{
public:
	// 0 ms, faster than 100% : 10.2 MB, less than 94.23%
	int solution(vector<int> nums) {
		vector<int> arr(3, 0);
		for (auto x : nums) {
			arr[0] = x;
			sort(begin(arr), end(arr));
			Printer::print(arr);
		}
		return (arr[1] - 1) * (arr[2] - 1);
	}
	vector<int> output = {
		12,
		16,
		12
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,4,5,2},
		{1,5,4,5},
		{3,7}
	};
};