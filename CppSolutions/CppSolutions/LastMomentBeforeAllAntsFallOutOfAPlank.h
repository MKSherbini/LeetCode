#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

class LastMomentBeforeAllAntsFallOutOfAPlank
{
public:
	// 11 ms, faster than 97.41% : 23 MB, less than 59.05%
	int solution(int n, vector<int> left, vector<int> right) {
		int ans = 0;
		for (auto x : left)
			ans = max(ans, x);
		for (auto x : right)
			ans = max(ans, n - x);
		return ans;
	}
	vector<int> output = {
		4,
		7,
		7
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		4,
		7,
		7
	};
	vector<vector<int>> input2 = {
		{4,3},
		{},
		{0,1,2,3,4,5,6,7}
	};
	vector<vector<int>> input3 = {
		{0,1},
		{0,1,2,3,4,5,6,7},
		{}
	};
};