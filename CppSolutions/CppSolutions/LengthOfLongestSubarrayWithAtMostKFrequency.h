#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

class LengthOfLongestSubarrayWithAtMostKFrequency
{
public:
	// 187 ms, faster than 93.95% : 148.3 MB, less than 86.23%
	int solution(vector<int> nums, int k) {
		int n = size(nums);
		int ans = 0;
		unordered_map<int, int> m;
		for (int i = 0, st = 0; i < n; i++)
		{
			m[nums[i]]++;
			while (m[nums[i]] > k && st < i) {
				m[nums[st]]--;
				st++;
			}
			Printer::print(st, i);
			ans = max(ans, i - st + 1);
		}
		return ans;
	}
	vector<int> output = {
		6,
		2,
		4
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,1,2,3,1,2},
		{1,2,1,2,1,2,1,2},
		{5,5,5,5,5,5,5}
	};
	vector<int> input2 = {
		2,
		1,
		4
	};
};