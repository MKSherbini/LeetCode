#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/combinations/

class NumberOfGoodPairs
{
public:
	// 0 ms, faster than 100.00% : 7.1 MB, less than 99.80%
	int solution(vector<int>& nums) {
		int cnt = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] == nums[j]) cnt++;
			}
		}
		return cnt;
	}
};

