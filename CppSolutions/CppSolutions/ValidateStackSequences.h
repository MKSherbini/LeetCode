#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/validate-stack-sequences/

class ValidateStackSequences
{
public:
	// 0 ms, faster than 100% : 15.2 MB, less than 98.01%
	bool solution(vector<int> pushed, vector<int> popped) {
		int n = size(popped);
		stack<int> st;

		int j = 0;
		for (auto x : pushed) {
			while (!st.empty() && st.top() == popped[j])
				j++, st.pop();
			st.push(x);
		}
		while (!st.empty() && st.top() == popped[j])
			j++, st.pop();

		return j == n;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,4,5},
		{1,2,3,4,5}
	};
	vector<vector<int>> input2 = {
		{4,5,3,2,1},
		{4,3,5,1,2}
	};
};