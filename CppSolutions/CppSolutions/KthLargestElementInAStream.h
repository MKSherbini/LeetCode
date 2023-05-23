#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargestElementInAStream
{
public:
	// 44 ms, faster than 17.92% : 22.1 MB, less than 5.28%
	KthLargestElementInAStream(int k, vector<int>& nums) {
		this->k = k;
		for (size_t i = 0; i < size(nums); i++) {
			add(nums[i]);
		}
	}

	int add(int val) {
		s.insert(val);
		if (size(s) > k)
			s.erase(s.begin());
		return *s.begin();
	}
private:
	multiset<int> s;
	int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */