#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/subarrays-with-k-different-integers/

class SubarraysWithKDifferentIntegers
{
public:
	// 61 ms, faster than 91.15% : 43 MB, less than 90.41%
	int solution(vector<int> nums, int k) {
		int n = size(nums);
		int ans = 0;
		unordered_map<int, int> m;
		int end = 0, st = 0, cnt = 0;
		for (int i = 0, st = 0; i < n; i++) {
			m[nums[i]]++;
			if (size(m) > k) {
				m[nums[st]]--;
				if (!m[nums[st]]) m.erase(nums[st]);
				st++;
				cnt = 0;
			}
			if (size(m) == k) {
				while (m[nums[st]] > 1) {
					m[nums[st]]--;
					st++;
					cnt++;
				}
				ans += cnt + 1;
			}
		}
		return ans;
	}
	vector<int> output = {
		7,
		3
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,1,2,3},
		{1,2,1,3,4}
	};
	vector<int> input2 = {
		2,
		3
	};
};