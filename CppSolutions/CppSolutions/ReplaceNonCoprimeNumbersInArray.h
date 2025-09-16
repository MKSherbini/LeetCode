#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/replace-non-coprime-numbers-in-array

class ReplaceNonCoprimeNumbersInArray
{
public:
	// 18 ms, faster than 68.98% : 124.57 MB, less than 98.61%
	vector<int> solution(vector<int> nums) {
		stack<int> st;
		for (auto x : nums) {
			while (!st.empty()) {
				int g = gcd(st.top(), x);
				if (g == 1) break;
				x = x / g * st.top();
				st.pop();
			}
			st.push(x);
		}

		vector<int> ans(st.size());
		for (int i = (int)st.size() - 1; i >= 0; --i) {
			ans[i] = st.top();
			st.pop();
		}

		return ans;
	}
	vector<vector<int>> output = {
		{12,7,6},
		{2,1,1,3}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{6,4,3,2,7,6,2},
		{2,2,1,1,3,3,3}
	};
};