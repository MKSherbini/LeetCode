#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/majority-element-ii/

class MajorityElementII
{
public:
	// 3 ms, faster than 99.07% : 16.1 MB, less than 28.2%
	vector<int> solution(vector<int> nums) {
		vector<int> ans;
		int c1 = 0, c2 = 1, cnt1 = 0, cnt2 = 0;

		for (int x : nums) {
			if (x == c1) cnt1++;
			else if (x == c2) cnt2++;
			else if (cnt1 == 0) c1 = x, cnt1 = 1;
			else if (cnt2 == 0) c2 = x, cnt2 = 1;
			else cnt1--, cnt2--;
		}

		cnt1 = cnt2 = 0;
		for (int x : nums) {
			if (x == c1) cnt1++;
			if (x == c2) cnt2++;
		}

		if (cnt1 > size(nums) / 3) ans.push_back(c1);
		if (cnt2 > size(nums) / 3) ans.push_back(c2);

		return ans;
	}

	// 3 ms, faster than 99.07% : 16.2 MB, less than 28.2%
	vector<int> solution2(vector<int> nums) {
		int n = size(nums);
		unordered_map<int, int> m;
		for (auto x : nums) {
			m[x]++;
		}

		vector<int> ans;
		int threshold = (n + 2) / 3;
		if (threshold == n / 3) threshold++;

		for (auto [x, f] : m) {
			if (f >= threshold) ans.push_back(x);
		}

		return ans;
	}
	vector<vector<int>> output = {
		{3},
		{1},
		{1},
		{1,2}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,2,3},
		{1},
		{1,4,4,5,6,3,7,1,1,1},
		{1,2}
	};
};