#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimize-deviation-in-array/

class MinimizeDeviationInArray
{
public:
	// 302 ms, faster than 96.61% : 88.9 MB, less than 43.22%
	int solution(vector<int> nums) {
		set<int> s;
		for (auto x : nums)
			s.insert(x % 2 ? x * 2 : x);

		auto mx = prev(end(s));
		int ans = *mx - *begin(s);
		while (*mx % 2 == 0) {
			Printer::print(s);
			s.insert(*mx / 2), s.erase(mx), mx = prev(end(s));
			ans = min(ans, *mx - *begin(s));
		}

		return ans;
	}

	vector<int> output = {
		1,
		3,
		3,
		1,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4},
		{4,1,5,20,3},
		{2,10,8},
		{3,5},
		{3,4,10}
	};
};