#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/asteroid-collision/

class AsteroidCollision
{
public:
	// 7 ms, faster than 99.05% : 17.5 MB, less than 85.34%
	vector<int> solution(vector<int> asteroids) {
		stack<int> st;
		vector<int> ans;
		for (auto x : asteroids) {
			if (x > 0) {
				st.push(x);
			}
			else {
				while (!empty(st) && st.top() < -x) {
					st.pop();
				}
				if (empty(st)) ans.push_back(x);
				else if (st.top() == -x) st.pop();
			}
		}
		int s = size(ans);
		while (!empty(st)) ans.push_back(st.top()), st.pop();
		reverse(begin(ans) + s, end(ans));

		return ans;
	}
	vector<vector<int>> output = {
		{5,10},
		{},
		{10}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{5,10,-5},
		{8,-8},
		{10,2,-5}
	};
};