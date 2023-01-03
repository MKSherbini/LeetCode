#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/delete-columns-to-make-sorted/

class DeleteColumnsToMakeSorted
{
public:
	// 41 ms, faster than 94.2% : 12 MB, less than 95.24%
	int solution(vector<string> strs) {
		int ans = 0;
		int n = size(strs), m = size(strs[0]);
		for (size_t j = 0; j < m; j++)
		{
			for (size_t i = 1; i < n; i++)
			{
				if (strs[i][j] < strs[i - 1][j]) {
					ans++;
					break;
				}
			}
		}
		return ans;
	}
	vector<int> output = {
		1,
		0,
		3
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"cba","daf","ghi"},
		{"a","b"},
		{"zyx","wvu","tsr"}
	};
};