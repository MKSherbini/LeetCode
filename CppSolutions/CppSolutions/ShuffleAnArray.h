#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/shuffle-an-array/

class ShuffleAnArray
{
public:
	// 62 ms, faster than 99% : 56.9 MB, less than 98.67%
	ShuffleAnArray(vector<int>& nums) {
		this->nums = nums;
	}

	vector<int> reset() {
		return nums;
	}

	vector<int> shuffle() {
		vector<int> ret = nums;
		int sz = nums.size();
		for (size_t i = 0; i < sz; i++)
			swap(ret[i], ret[rand() % sz]);
		return ret;
	}

private:
	vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */