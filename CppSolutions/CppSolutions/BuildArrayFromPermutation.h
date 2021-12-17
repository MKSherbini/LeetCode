#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/build-array-from-permutation/

class BuildArrayFromPermutation
{
public:
	// 11 ms, faster than 82.08% : 16.2 MB, less than 92.54%
	vector<int> solution(vector<int>& v) {
		auto ans = v;
		for (int i = 0; i < v.size(); i++)
		{
			ans[i] = v[v[i]];
		}
		return ans;
	}
};

