#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-elements-with-maximum-frequency/

class CountElementsWithMaximumFrequency
{
public:
	// 0 ms, faster than 100% : 22.2 MB, less than 13.39%
	int solution(vector<int> nums) {
		vector<int> f(100);
		for (auto x : nums) f[x - 1]++;
		sort(begin(f), end(f), greater());

		int ans = 0;
		for (auto x : f)
			if (x == f[0]) ans += x;
			else break;

		return ans;
	}
	vector<int> output = {
		4,
		5
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,2,3,1,4},
		{1,2,3,4,5}
	};
};