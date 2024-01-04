#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/two-sum/

class TwoSum
{
public:
	// 3 ms, faster than 99.33% : 11.4 MB, less than 21%
	vector<int> solution(vector<int> nums, int target) {
		unordered_map<int, int> m;
		for (int i = 0; i < size(nums); i++) {
			if (m.count(target - nums[i])) return { i, m[target - nums[i]] };
			m[nums[i]] = i;
		}

		return {};
	}

	// 3 ms, faster than 99.33% : 11.5 MB, less than 16.02%
	vector<int> solution2(vector<int> nums, int target) {
		vector<pair<int, int>> v;
		for (size_t i = 0; i < size(nums); i++) {
			v.push_back({ nums[i], i });
		}
		sort(begin(v), end(v));

		int i = 0, j = size(nums) - 1;

		while (i < j) {

			if (v[i].first + v[j].first < target) {
				i++;
			}
			else if (v[i].first + v[j].first > target) {
				j--;
			}
			else {
				return { v[i].second, v[j].second };
			}
		}

		return {};
	}
	vector<vector<int>> output = {
		{0,1},
		{1,2},
		{0,1}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{2,7,11,15},
		{3,2,4},
		{3,3}
	};
	vector<int> input2 = {
		9,
		6,
		6
	};
};