#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

class LongestPathWithDifferentAdjacentCharacters
{
public:
	// 713 ms, faster than 57.95% : 237.8 MB, less than 16.14%
	int solution(vector<int> parent, string s) {
		int n = size(s);
		vector<vector<int>> mat(n);

		for (size_t i = 1; i < n; i++)
			mat[parent[i]].push_back(i);

		return max(ans, f(mat, s, 0));
	}
	int ans = 0;
	int f(vector<vector<int>>& mat, string& s, int i) {
		vector<int> mx(3, 0);
		for (auto j : mat[i]) {
			if (s[i] == s[j]) {
				ans = max(ans, f(mat, s, j));
			}
			else {
				mx[2] = f(mat, s, j);
				sort(begin(mx), end(mx), greater());
			}
		}
		ans = max(ans, mx[0] + mx[1] + 1);
		return mx[0] + 1;
	}
	vector<int> output = {
		3,
		3
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{-1,0,0,1,1,2},
		{-1,0,0,0}
	};
	vector<string> input2 = {
		"abacbe",
		"aabc"
	};
};