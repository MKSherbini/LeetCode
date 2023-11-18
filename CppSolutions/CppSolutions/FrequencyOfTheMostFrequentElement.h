#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class FrequencyOfTheMostFrequentElement
{
public:
	// 155 ms, faster than 92.52% : 99.2 MB, less than 85.2%
	int solution(vector<int> nums, int k) {
		sort(begin(nums), end(nums));
		int n = size(nums);
		int ans = 1, i = 0;
		long long used = 0;
		for (int j = 1; j < n; j++) {
			int diff = nums[j] - nums[j - 1];
			used += 1ll * diff * (j - i);
			while (used > k) {
				used -= nums[j] - nums[i];
				i++;
			}
			ans = max(ans, j - i + 1);
			Printer::print(j, i, ans);
		}

		return ans;
	}
	vector<int> output = {
		3,
		2,
		1
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,4},
		{1,4,8,13},
		{3,9,6}
	};
	vector<int> input2 = {
		5,
		5,
		2
	};
};