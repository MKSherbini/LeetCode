#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-original-array-from-doubled-array/

class FindOriginalArrayFromDoubledArray
{
public:
	// 298 ms, faster than 98.13% : 117.4 MB, less than 96.81%
	vector<int> solution(vector<int> changed) {
		int n = size(changed);
		if (n % 2) return {};
		sort(begin(changed), end(changed));
		Printer::print(changed);

		vector<int> ans;
		int i = 0, j = lower_bound(begin(changed) + 1, end(changed), changed[i] * 2) - begin(changed);

		while (j < n) {
			Printer::print(i, j);

			if (changed[i] * 2 != changed[j]) break;
			ans.push_back(changed[i]);
			changed[j] = -1;
			changed[i] = -1;

			while (i < n && changed[i] == -1) ++i;

			if (i >= n) break;

			j = lower_bound(begin(changed) + max(j, i) + 1, end(changed), changed[i] * 2) - begin(changed);
		}
		return size(ans) * 2 == n ? ans : vector<int>{};
	}
	vector<vector<int>> output = {
		{1,3,4},
		{0,0},
		{},
		{}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,3,4,2,6,8},
		{0,0,0,0},
		{6,3,0,1},
		{1}
	};
};