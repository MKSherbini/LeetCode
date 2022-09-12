#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-the-duplicate-number/

class FindTheDuplicateNumber
{
public:
	// 96 ms, faster than 99.75% : 61.2 MB, less than 91.44%
	int solution(vector<int> nums) {
		int slow = 0, fast = 0;

		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
			Printer::print(slow, fast);
		} while (fast != slow);
		fast = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}

	// WA: allows multiple repeats
	int solution2(vector<int> nums) {
		int n = size(nums) - 1;
		int sum = -n * (n + 1) / 2;
		for (size_t i = 0; i < n + 1; i++)
			sum += nums[i];

		return sum;
	}
	vector<int> output = {
		2,
		3,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,3,4,2,2},
		{3,1,3,4,2},
		{2,2,2,2,2}
	};
};