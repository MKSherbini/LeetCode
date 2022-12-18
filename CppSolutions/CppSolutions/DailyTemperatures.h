#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/daily-temperatures/

class DailyTemperatures
{
public:
	// 205 ms, faster than 94.62% : 102.8 MB, less than 53.89%
	vector<int> solution(vector<int> temperatures) {
		stack<int> st;

		for (size_t i = 0; i < size(temperatures); i++) {
			while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
				temperatures[st.top()] = i - st.top();
				st.pop();
			}

			st.push(i);
		}

		while (!st.empty())
			temperatures[st.top()] = 0, st.pop();

		return temperatures;
	}
	vector<vector<int>> output = {
		{1,1,4,2,1,1,0,0},
		{1,1,1,0},
		{1,1,0}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{73,74,75,71,69,72,76,73},
		{30,40,50,60},
		{30,60,90}
	};
};