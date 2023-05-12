#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/solving-questions-with-brainpower/

class SolvingQuestionsWithBrainpower
{
public:
	// 410 ms, faster than 15.28% : 146.8 MB, less than 8.99%
	long long solution(vector<vector<int>> questions) {
		int n = size(questions);
		vector<long long> mem(n, 0);
		mem.back() = questions.back()[0];

		for (int i = n - 2; i >= 0; i--) {
			long long s = questions[i][0];
			if (i + questions[i][1] + 1 < n)
				s += mem[i + questions[i][1] + 1];

			mem[i] = max(mem[i + 1], s);
		}

		return mem[0];
	}

	// 410 ms, faster than 15.28% : 146.8 MB, less than 8.99%
	long long solution2(vector<vector<int>> questions) {
		int n = size(questions);
		vector<long long> mem(n, -1);
		function<long long(int)> f = [&](int i)->long long {
			if (i >= n) return 0;
			if (mem[i] != -1) return mem[i];

			return mem[i] = max(f(i + 1), questions[i][0] + f(i + questions[i][1] + 1));
		};

		return f(0);
	}
	vector<int> output = {
		5,
		7
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{3,2},{4,3},{4,4},{2,5}},
		{{1,1},{2,2},{3,3},{4,4},{5,5}}
	};
};