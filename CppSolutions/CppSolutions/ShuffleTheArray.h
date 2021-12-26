#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/shuffle-the-array/

class ShuffleTheArray
{
public:
	// 0 ms, faster than 100.00% : 9.5 MB, less than 99.97%
	vector<int> solution(vector<int>& nums, int n) {
		vector<int> ret(2 * n);
		for (int i = 0; i < n; i++)
			ret[i * 2] = nums[i], ret[i * 2 + 1] = nums[i + n];
		return ret;
	}
};
// x => i*2
// y => (i-n)*2+1 
