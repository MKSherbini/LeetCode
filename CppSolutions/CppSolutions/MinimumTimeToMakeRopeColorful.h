#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

class MinimumTimeToMakeRopeColorful
{
public:
	// 142 ms, faster than 99.49% : 95.3 MB, less than 84.76%
	int solution(string colors, vector<int> neededTime) {
		int n = size(neededTime);
		int ans = 0;
		for (size_t i = 0; i + 1 < n; i++)
		{
			int j = i;
			int mx = neededTime[j];
			int total = mx;
			while (j + 1 < n && colors[j] == colors[j + 1]) {
				++j;
				if (mx < neededTime[j]) mx = neededTime[j];
				total += neededTime[j];
			}

			if (i == j) continue;
			ans += total - mx;
			i = j;
		}

		return ans;
	}

	// WA empty spaces doesn't separate
	int solution2(string colors, vector<int> neededTime) {
		int n = size(neededTime);
		int ans = 0;
		for (size_t i = 0; i < n + 1; i++)
		{
			int j = i;

			while (j + 1 < n && colors[j] == colors[j + 1])
				++j;

			if (i == j) continue;
			ans += f(colors, neededTime, i, j, 0);
			i = j;
		}

		return ans;
	}

	int f(string& colors, vector<int>& neededTime, int i, int end, int pickedLast) {
		if (i >= end + 1) return 0;

		int ret = neededTime[i] + f(colors, neededTime, i + 1, end, 0);

		if (!pickedLast)
			ret = min(ret, f(colors, neededTime, i + 1, end, 1));

		return ret;
	}
	int const OO = 1e9 + 7;
	vector<int> output = {
		3,
		0,
		2,
		13
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"abaac",
		"abc",
		"aabaa",
		"abaaaa"
	};
	vector<vector<int>> input2 = {
		{1,2,3,4,5},
		{1,2,3},
		{1,2,3,4,1},
		{1,2,5,4,4,5}
	};
};