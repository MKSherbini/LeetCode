#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/course-schedule/

class CourseSchedule
{
public:
	// 15 ms, faster than 98.49% : 14.1 MB, less than 37.97%
	bool solution(int numCourses, vector<vector<int>> prerequisites) {
		vector<vector<int>> adj(numCourses);
		vector<int> s(numCourses, -1);

		for (auto& v : prerequisites) {
			adj[v[0]].push_back(v[1]);
		}

		function<bool(int)> f = [&](int i) -> bool {
			if (s[i] != -1) return s[i];
			if (empty(adj[i])) return s[i] = 1;
			s[i] = -2;
			bool ret = 1;

			for (auto& j : adj[i]) {
				if (s[j] == -2) return s[i] = false;
				ret &= f(j);
				if (!ret) return s[i] = ret;
			}

			return s[i] = ret;
		};

		for (size_t i = 0; i < numCourses; i++) {
			if (!f(i)) return false;
		}

		return true;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		2,
		2
	};
	vector<vector<vector<int>>> input2 = {
		{{1,0}},
		{{1,0},{0,1}}
	};
};