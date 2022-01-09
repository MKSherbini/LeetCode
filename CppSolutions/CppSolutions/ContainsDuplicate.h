#pragma once
#include "stdc++.h"
#include <unordered_map>
using namespace std;

//https://leetcode.com/problems/contains-duplicate/

class ContainsDuplicate
{
public:
	// 72 ms, faster than 52.44% : 51.2 MB, less than 33.72%
	int solution(vector<int>& nums) {
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m[nums[i]]) return true;
			m[nums[i]] = 1;
		}
		return false;
	}
	vector<int> output = {
		true,
		false,
		true,
	};
	vector<vector<int>> input1 = {
		{1,2,3,1},
		{1,2,3,4},
		{1,1,1,3,3,4,3,2,4,2},
	};
};

