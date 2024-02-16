#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

class FindPolygonWithTheLargestPerimeter
{
public:
	// 121 ms, faster than 98.39% : 83.1 MB, less than 36.48%
	int solution(vector<int> nums) {
		sort(begin(nums), end(nums));
		long long ans = -1, sum = nums[0] + nums[1];
		for (int i = 2; i < size(nums); i++) {
			if (nums[i] < sum) {
				ans = nums[i] + sum;
			}
			sum += nums[i];
		}
		return ans;
	}
	vector<int> output = {
		15,
		12,
		-1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{5,5,5},
		{1,12,1,2,5,50,3},
		{5,5,50}
	};
};