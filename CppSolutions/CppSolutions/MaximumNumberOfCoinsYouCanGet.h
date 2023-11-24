#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

class MaximumNumberOfCoinsYouCanGet
{
public:
	// 78 ms, faster than 96.58% : 53.7 MB, less than 55.19%
	int solution(vector<int> piles) {
		int n = size(piles);
		sort(begin(piles), end(piles));

		int ans = 0;
		for (int i = n - 2; i >= n / 3; i -= 2) {
			ans += piles[i];
		}

		return ans;
	}
	vector<int> output = {
		9,
		4,
		18
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,4,1,2,7,8},
		{2,4,5},
		{9,8,7,6,5,1,2,3,4}
	};
};