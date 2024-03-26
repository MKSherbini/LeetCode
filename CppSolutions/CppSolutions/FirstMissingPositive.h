#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/first-missing-positive/

class FirstMissingPositive
{
public:
	// 33 ms, faster than 94.14% : 43.4 MB, less than 95.87%
	int solution(vector<int> nums) {
		int n = size(nums);

		int i = 0;
		while (i < n) {
			if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
				swap(nums[i], nums[nums[i] - 1]);
			else i++;
		}

		for (i = 0; i < n; i++) {
			if (nums[i] != i + 1) return i + 1;
		}

		Printer::print(nums);

		return n + 1;
	}

	// 70 ms, faster than 18.8% : 60.6 MB, less than 15.38%
	int solution2(vector<int> nums) {
		int n = size(nums);
		unordered_set<int> s;

		for (auto x : nums) {
			s.insert(x);
		}

		for (size_t i = 1; i <= n + 1; i++) {
			if (!s.count(i)) return i;
		}

		return 66;
	}
	vector<int> output = {
		3,
		2,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,0},
		{3,4,-1,1},
		{7,8,9,11,12}
	};
};



// 