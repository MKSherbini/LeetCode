#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/build-an-array-with-stack-operations/

class BuildAnArrayWithStackOperations
{
public:
	// 0 ms, faster than 100% : 8 MB, less than 75.36%
	vector<string> solution(vector<int> target, int n) {
		vector<string> ans;
		int j = 0, sz = size(target);
		for (size_t i = 1; i <= n; i++) {
			ans.push_back("Push");
			if (i != target[j]) ans.push_back("Pop");
			else j++;
			if (j == sz) break;
		}

		return ans;
	}
	vector<vector<string>> output = {
		{"Push","Push","Pop","Push"},
		{"Push","Push","Push"},
		{"Push","Push"}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,3},
		{1,2,3},
		{1,2}
	};
	vector<int> input2 = {
		3,
		3,
		4
	};
};