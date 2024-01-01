#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/assign-cookies/

class AssignCookies
{
public:
	// 20 ms, faster than 78.06% : 17.6 MB, less than 98.96%
	int solution(vector<int> g, vector<int> s) {
		sort(begin(g), end(g));
		sort(begin(s), end(s));
		int child = size(g) - 1, cookie = size(s) - 1;
		if (cookie == -1) return 0;

		int ans = 0;
		while (child >= 0 && cookie >= 0) {
			if (s[cookie] >= g[child]) cookie--, child--, ans++;
			else child--;
		}

		return ans;
	}
	vector<int> output = {
		1,
		2
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3},
		{1,2}
	};
	vector<vector<int>> input2 = {
		{1,1},
		{1,2,3}
	};
};