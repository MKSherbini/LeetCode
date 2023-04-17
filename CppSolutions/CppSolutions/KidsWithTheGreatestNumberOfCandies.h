#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class KidsWithTheGreatestNumberOfCandies
{
public:
	// 0 ms, faster than 100% : 8.8 MB, less than 98.95%
	vector<bool> solution(vector<int> candies, int extraCandies) {
		int mx = *max_element(begin(candies), end(candies));
		int n = size(candies);
		vector<bool> ans(n);
		for (size_t i = 0; i < n; i++)
			ans[i] = mx <= extraCandies + candies[i];
		return ans;
	}
	vector<vector<bool>> output = {
		{true,true,true,false,true},
		{true,false,false,false,false},
		{true,false,true}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{2,3,5,1,3},
		{4,2,1,1,2},
		{12,1,12}
	};
	vector<int> input2 = {
		3,
		1,
		10
	};
};